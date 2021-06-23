#include "gtest/gtest.h"

#include "HDMapTests.hpp"

namespace opendrive {
    namespace tests {

        /**
         * Base setup for the geometry calculation tests.
         */
        class GeometryTests : public HDMapTests {
        public:
            /**
             * @destrcutor
             */
            ~GeometryTests() override = default;

        protected:

            /**
             * Asserts that the interpolation for the start and end of a parametric cubic curve works as expected, i.e.
             * that the interpolated end point is the start of the next geometry.
             */
            void assertStartAndEnd(const Geometry &paramPoly3Geometry) {
                Vector expected = paramPoly3Geometry.getStart();
                auto distance = expected.distance(paramPoly3Geometry.interpolateStart());
                EXPECT_NEAR(distance, 0, maxDifference);

                expected = roadHighwayNorth.getElement<Geometry>(
                        paramPoly3Geometry.getEndSCoordinate() + 0.5).getStart();
                distance = expected.distance(paramPoly3Geometry.interpolateEnd());
                EXPECT_NEAR(distance, 0, 1e-6);
            }

            /**
             * Asserts that the calculation of the reference s tangent is correct.
             * Calculates the tangent at the end of the geometry and the start of the next one and asserts that they are near equal.
             */
            static void assertTangent(const Geometry &geometry, const Geometry &nextGeometry) {
                Vector endTangent = geometry.calculateTangent(geometry.getEndSCoordinate());
                Vector nextStartTangent = nextGeometry.calculateTangent(nextGeometry.s);

                EXPECT_NEAR(endTangent.distance(nextStartTangent), 0, 1e-12);
            }

            /**
             * Asserts that the calculation of the reference t normal is correct.
             * Calculates the normal at 1 meter steps along the geometry and checks if the dot product of the normal and tangent is 0.
             */
            static void assertTangentAndNormalOrthogonal(const Geometry &geometry) {
                Vector tangent, normal;
                tangent = geometry.calculateTangent(geometry.s);
                normal = geometry.calculateNormal(geometry.s);
                EXPECT_NEAR(tangent.dot(normal), 0, 1e-16);

                for (int ss = (int) geometry.s + 1; ss < geometry.getEndSCoordinate(); ss++) {
                    tangent = geometry.calculateTangent(ss);
                    normal = geometry.calculateNormal(ss);
                    EXPECT_NEAR(tangent.dot(normal), 0, 1e-16);
                }

                tangent = geometry.calculateTangent(geometry.getEndSCoordinate());
                normal = geometry.calculateNormal(geometry.getEndSCoordinate());
                EXPECT_NEAR(tangent.dot(normal), 0, 1e-16);
            }
        };

        /**
         * Tests that the parametric cubic curve interpolation works as expected.
         */
        TEST_F(GeometryTests, testInterpolateParamPoly3) {
            for (const auto &s : roadHighwayExitSouth.getStartCoordinates<Geometry>(true)) {
                assertStartAndEnd(roadHighwayNorth.getElement<Geometry>(s));
            }
        }


        /**
         * Tests that calculated s tangent of the parametric cubic curve primitive is correct.
         */
        TEST_F(GeometryTests, testCalculateParamPoly3ReferenceTangentS) {
            for (const auto &s : roadHighwayExitSouth.getStartCoordinates<Geometry>(true)) {
                auto geometry = roadHighwayExitSouth.getElement<Geometry>(s);
                auto nextGeometry = roadHighwayExitSouth.getElement<Geometry>(geometry.getEndSCoordinate() + 0.5);
                assertTangent(geometry, nextGeometry);
            }
        }

        /**
         * Tests that calculated t normal of the parametric cubic curve primitive is correct.
         */
        TEST_F(GeometryTests, testCalculateParamPoly3ReferenceNormal) {
            for (const auto &s : roadHighwayExitSouth.getStartCoordinates<Geometry>(true)) {
                assertTangentAndNormalOrthogonal(roadHighwayExitSouth.getElement<Geometry>(s));
            }
        }
    }// namespace tests
}// namespace opendrive