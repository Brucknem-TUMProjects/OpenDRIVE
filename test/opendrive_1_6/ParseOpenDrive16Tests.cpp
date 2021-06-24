#include <OpenDRIVE/HDMapFactory.hpp>
#include "gtest/gtest.h"

#include "OpenDRIVE/HDMap.hpp"

namespace opendrive {
    namespace opendrive_1_6 {
        namespace tests {

            /**
             * Base setup for the tests that parse the mock HD map.
             */
            class ParseOpenDrive16Tests : public ::testing::Test {
            public:

                /**
                 * The HD maps.
                 */
                std::shared_ptr<HDMap> testMapOpendrive16;

                /**
                 * The id of the test roads.
                 */
                const char *testRoadIdOpendrive16 = "1069000";

                /**
                 * The test roads.
                 */
                Road testRoadOpendrive16;

                /**
                 * The maximal difference after parsing.
                 */
                double maxDifference = 1e-52;

                /**
                 * @destrcutor
                 */
                ~ParseOpenDrive16Tests() override = default;

                /**
                 * @setup
                 */
                void SetUp() override {
                    testMapOpendrive16 = std::make_shared<HDMap>(
                            opendrive::createHDMap("../../misc/test_map_opendrive_1_6.xodr"));
                    testRoadOpendrive16 = testMapOpendrive16->getRoad(testRoadIdOpendrive16);
                };
            };

            /**
             * Tests parsing the HD map header.
             */
            TEST_F(ParseOpenDrive16Tests, testParsingHeader) {
                EXPECT_NEAR(testMapOpendrive16->getHeader().north, 2.221400906000e+3, maxDifference);
                ASSERT_STREQ(testMapOpendrive16->getHeader().vendor.c_str(), "3D Mapping Solutions");

                ASSERT_STREQ(testMapOpendrive16->getGeoReference().c_str(),
                             "+proj=tmerc +lat_0=0 +lon_0=9 +k=0.9996 +x_0=-196000 +y_0=-5348000 +datum=WGS84 +units=m +no_defs");
            }

//        /**
//         * Tests parsing the test road basic attributes.
//         */
//        TEST_F(ParsingTests, testParsingRoadAttributes) {
//            ASSERT_STREQ(testRoadOpenDrive14.getName().c_str(), "");
//            ASSERT_STREQ(testRoadOpenDrive14.getJunction().c_str(), "-1");
//            ASSERT_STREQ(testRoadOpenDrive14.getId().c_str(), testRoadIdOpenDrive14);
//            EXPECT_NEAR(testRoadOpenDrive14.getLength(), 1.724447338294e+03, maxDifference);
//        }
//
//        /**
//         * Tests parsingthe test road type.
//         */
//        TEST_F(ParsingTests, testParsingType) {
////            auto type = testRoadOpenDrive14.type[0];
//            ASSERT_EQ(testRoadOpenDrive14.getType().size(), 1);
//
////            EXPECT_NEAR(type.first, 0.0, maxDifference);
////            ASSERT_STREQ(type.second.c_str(), "motorway");
//        }
//
//        /**
//         * Tests parsing the test road plan view.
//         */
//        TEST_F(ParsingTests, testParsingPlanView) {
//            std::map<double, Geometry> planView = testRoadOpenDrive14.getPlanView();
//
//            ASSERT_EQ(planView.size(), 4);
//
//            auto geometry = planView[0];
//            EXPECT_NEAR(geometry.getU().a, -0.000000000000e+00, maxDifference);
//            EXPECT_NEAR(geometry.getU().b, 1.000000000000e+00, maxDifference);
//            EXPECT_NEAR(geometry.getU().c, -2.864238929279e-11, maxDifference);
//            EXPECT_NEAR(geometry.getU().d, 9.895389049440e-14, maxDifference);
//
//            EXPECT_NEAR(geometry.getV().a, 0.000000000000e+00, maxDifference);
//            EXPECT_NEAR(geometry.getV().b, 2.775557561563e-16, maxDifference);
//            EXPECT_NEAR(geometry.getV().c, -1.284829717715e-07, maxDifference);
//            EXPECT_NEAR(geometry.getV().d, 3.576738398807e-10, maxDifference);
//
////            ASSERT_STREQ(geometry.pRange.c_str(), "arcLength");
//        }
//
//        /**
//         * Tests parsing the test road elevation profile.
//         */
//        TEST_F(ParsingTests, testParsingElevationProfile) {
//            auto elevationProfile = testRoadOpenDrive14.getElevationProfile();
//            ASSERT_EQ(elevationProfile.size(), 12);
//
//            EXPECT_NEAR(elevationProfile[0].getS(), 0.000000000000e+00, maxDifference);
//
//            EXPECT_NEAR(elevationProfile[0].getPolynom().a, 5.299890546737e+02, maxDifference);
//            EXPECT_NEAR(elevationProfile[0].getPolynom().b, 1.580599780197e-03, maxDifference);
//            EXPECT_NEAR(elevationProfile[0].getPolynom().c, -1.160874186427e-05, maxDifference);
//            EXPECT_NEAR(elevationProfile[0].getPolynom().d, 6.476066427343e-08, maxDifference);
//        }
//
//        /**
//         * Tests parsing the test road lateral profile.
//         */
//        TEST_F(ParsingTests, testParsingLateralProfile) {
//            auto lateralProfile = testRoadOpenDrive14.getLateralProfile();
//            ASSERT_EQ(lateralProfile.size(), 9);
//
//            EXPECT_NEAR(lateralProfile[0].getS(), 0.000000000000e+00, maxDifference);
//
//            EXPECT_NEAR(lateralProfile[0].getPolynom().a, 3.192305336358e-02, maxDifference);
//            EXPECT_NEAR(lateralProfile[0].getPolynom().b, -7.543093979616e-05, maxDifference);
//            EXPECT_NEAR(lateralProfile[0].getPolynom().c, -4.921087190205e-08, maxDifference);
//            EXPECT_NEAR(lateralProfile[0].getPolynom().d, 1.391947694799e-09, maxDifference);
//        }
//
//        /**
//         * Tests parsing the test road objects.
//         */
//        TEST_F(ParsingTests, testParsingObjects) {
//            auto objects = testRoadOpenDrive14.getObjects();
//            ASSERT_EQ(objects.size(), 52);
//
//            std::string id = "4007953";
//            auto testObject = testRoadOpenDrive14.getElement<Object>(id);
//
//            ASSERT_STREQ(testObject.getType().c_str(), "pole");
//            ASSERT_STREQ(testObject.getName().c_str(), "permanentDelineator");
//            ASSERT_STREQ(testObject.getId().c_str(), "4007953");
//            EXPECT_NEAR(testObject.getS(), 1.0092e+02, maxDifference);
//            EXPECT_NEAR(testObject.getT(), -1.7770e+01, maxDifference);
//            EXPECT_NEAR(testObject.getZOffset(), -4.215e-01, maxDifference);
//            EXPECT_NEAR(testObject.getValidLength(), 0.00, maxDifference);
//            ASSERT_STREQ(testObject.getOrientation().c_str(), "none");
//            EXPECT_NEAR(testObject.getRadius(), 5.00e-02, maxDifference);
//            EXPECT_NEAR(testObject.getHeight(), 7.705e-01, maxDifference);
//            EXPECT_NEAR(testObject.getHdg(), 0.0000e+00, maxDifference);
//        }

        }// namespace tests
    }// namespace opendrive
}