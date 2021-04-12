//
// Created by brucknem on 24.02.21.
//

#include "Projector.hpp"
#include <memory>

namespace opendrive {
    const std::string Projector::LONG_LAT_PROJECTION = "+proj=longlat +datum=WGS84";

    Projector::Projector(const std::string &fromProjection, const std::string &toProjection) {
        context = proj_context_create();
        projection = proj_create_crs_to_crs(context,
                                            fromProjection.c_str(),
                                            toProjection.c_str(),
                                            nullptr);
        if (nullptr == projection) {
            throw std::invalid_argument("Couldn't create projection");
        }

        PJ *normalizedProjection = proj_normalize_for_visualization(context, projection);
        if (nullptr == normalizedProjection) {
            throw std::invalid_argument("Couldn't create projection");
        }
        proj_destroy(projection);
        projection = normalizedProjection;
    }

    Projector::~Projector() {
        proj_destroy(projection);
        proj_context_destroy(context);
    }

    Vector Projector::project(const Vector &vector, PJ_DIRECTION direction) const {
        PJ_COORD a, b;

        a = proj_coord(vector.getX(), vector.getY(), vector.getZ(), 0);
        b = proj_trans(projection, direction, a);

        return {b.lp.lam, b.lp.phi, vector.getZ()};
    }

    std::string Projector::toGoogleMapsLink(const Vector &vector) {
        return "https://www.google.de/maps/place/" + vector.format(52, false, {1, 0});
    }
}