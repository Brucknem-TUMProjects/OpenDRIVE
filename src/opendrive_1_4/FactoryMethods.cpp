//
// Created by brucknem on 12.07.21.
//

#include "OpenDRIVE/opendrive_1_4/FactoryMethods.hpp"

namespace opendrive {
    namespace opendrive_1_4 {


        template<>
        Elevation create(const elevation &openDriveObject) {
            return opendrive::Elevation(openDriveObject.s().get(),
                                        {openDriveObject.a().get(),
                                         openDriveObject.b().get(),
                                         openDriveObject.c().get(),
                                         openDriveObject.d().get()}
            );
        }

        CubicPolynom extractU(const geometry &openDriveObject) {
            if (openDriveObject.paramPoly3().present()) {
                return {openDriveObject.paramPoly3()->aU().get(),
                        openDriveObject.paramPoly3()->bU().get(),
                        openDriveObject.paramPoly3()->cU().get(),
                        openDriveObject.paramPoly3()->dU().get()};

            } else {
                return {0, 0, 0, 0};
            }
        }

        CubicPolynom extractV(const geometry &openDriveObject) {
            if (openDriveObject.paramPoly3().present()) {
                return {openDriveObject.paramPoly3()->aV().get(),
                        openDriveObject.paramPoly3()->bV().get(),
                        openDriveObject.paramPoly3()->cV().get(),
                        openDriveObject.paramPoly3()->dV().get()};

            } else {
                return {0, 0, 0, 0};
            }
        }

        template<>
        Geometry create(const geometry &openDriveObject) {
            return opendrive::Geometry(openDriveObject.s().get(),
                                       Vector{openDriveObject.x().get(),
                                              openDriveObject.y().get()},
                                       openDriveObject.hdg().get(),
                                       openDriveObject.length().get(),
                                       extractU(openDriveObject),
                                       extractV(openDriveObject));
        }

        std::string extractOrientation(const object &openDriveObject) {
            std::string orientation;
            if (openDriveObject.orientation().present()) {
                orientation = openDriveObject.orientation().get().c_str();
            }
            if (orientation.empty()) {
                orientation = "none";
            }
            return orientation;
        }

        template<>
        Object create(const object &openDriveObject) {
            return opendrive::Object(openDriveObject.s().get(),
                                     openDriveObject.t().get(),
                                     openDriveObject.type().get().c_str(),
                                     openDriveObject.name().get().c_str(),
                                     openDriveObject.id().get().c_str(),
                                     openDriveObject.height().get(),
                                     openDriveObject.hdg().get(),
                                     openDriveObject.validLength().get(),
                                     extractOrientation(openDriveObject),
                                     openDriveObject.pitch().get(),
                                     openDriveObject.roll().get(),
                                     openDriveObject.length().get(),
                                     openDriveObject.width().get(),
                                     openDriveObject.radius().get(),
                                     openDriveObject.zOffset().get());
        }


        template<>
        opendrive::Shape create(const shape &openDriveObject) {
            return opendrive::Shape(
                    openDriveObject.s().get(),
                    openDriveObject.t().get(),
                    {openDriveObject.a().get(),
                     openDriveObject.b().get(),
                     openDriveObject.c().get(),
                     openDriveObject.d().get()}
            );
        }

        template<>
        SuperElevation create(const superelevation &openDriveObject) {
            return opendrive::SuperElevation(
                    openDriveObject.s().get(),
                    {openDriveObject.a().get(),
                     openDriveObject.b().get(),
                     openDriveObject.c().get(),
                     openDriveObject.d().get()}
            );
        }

        std::vector<opendrive::Object> extractObjects(const road &openDriveObject) {
            std::vector<opendrive::Object> objects;
            if (openDriveObject.objects().present()) {
                for (const auto &objectNode : openDriveObject.objects().get().object()) {
                    objects.emplace_back(create<Object>(objectNode));
                }
            }
            return objects;
        }

        std::vector<opendrive::Geometry> extractGeometry(const road &openDriveObject) {
            std::vector<opendrive::Geometry> planView;
            for (const geometry &geometryNode : openDriveObject.planView().geometry()) {
                planView.emplace_back(create<Geometry>(geometryNode));
            }
            return planView;
        }

        std::vector<opendrive::Elevation> extractElevation(const road &openDriveObject) {
            std::vector<opendrive::Elevation> elevationProfile;
            for (const auto &elevationNode : openDriveObject.elevationProfile().get().elevation()) {
                elevationProfile.emplace_back(create<Elevation>(elevationNode));
            }
            return elevationProfile;
        }

        std::vector<opendrive::SuperElevation> extractSuperElevation(const road &openDriveObject) {
            std::vector<opendrive::SuperElevation> lateralProfile;
            for (const auto &superElevationNode : openDriveObject.lateralProfile().get().superelevation()) {
                lateralProfile.emplace_back(create<SuperElevation>(superElevationNode));
            }
            return lateralProfile;
        }

        std::vector<opendrive::Shape> extractShape(const road &openDriveObject) {
            std::vector<opendrive::Shape> lateralProfile;
            for (const auto &shapeNode : openDriveObject.lateralProfile().get().shape()) {
                lateralProfile.emplace_back(create<Shape>(shapeNode));
            }
            return lateralProfile;
        }

        std::vector<Road::Type> convertToType(const road &openDriveRoad) {
            std::vector<Road::Type> result;
            for (const auto &type : openDriveRoad.type()) {
                result.emplace_back(Road::Type{
                        type.s().get(),
                        type.type().get().c_str()
                });
            }
            return result;
        }

        template<>
        opendrive::Road create(const road &openDriveRoad) {
            const char *roadId = openDriveRoad.id()->c_str();
            return opendrive::Road(
                    roadId,
                    openDriveRoad.name()->c_str(),
                    openDriveRoad.length().get(),
                    openDriveRoad.junction().get().c_str(),
                    convertToType(openDriveRoad),
                    extractObjects(openDriveRoad),
                    extractGeometry(openDriveRoad),
                    extractElevation(openDriveRoad),
                    extractSuperElevation(openDriveRoad),
                    extractShape(openDriveRoad)
            );
        }

        std::map<std::string, opendrive::Road> extractRoads(const OpenDRIVE &openDriveObject) {
            std::map<std::string, opendrive::Road> roads;
            for (const auto &openDriveRoad : openDriveObject.road()) {
                roads.emplace(openDriveRoad.id().get(), create<Road>(openDriveRoad));
            }
            return roads;
        }

        HDMap::Header extractHeader(const OpenDRIVE &openDriveObject) {
            return HDMap::Header{
                    openDriveObject.header().geoReference()->c_str(),
                    openDriveObject.header().vendor()->c_str(),
                    openDriveObject.header().north().get(),
                    openDriveObject.header().south().get(),
                    openDriveObject.header().east().get(),
                    openDriveObject.header().west().get(),
            };
        }

        template<>
        HDMap create(const std::string &filename) {
            return opendrive::HDMap(filename,
                                    extractRoads(*OpenDRIVE_(filename, ::xml_schema::flags::dont_validate)),
                                    extractHeader(*OpenDRIVE_(filename, ::xml_schema::flags::dont_validate))
            );
        }
    }
}