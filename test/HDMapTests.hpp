//
// Created by brucknem on 22.02.21.
//

#ifndef OPENDRIVE_HDMAPTESTS_HPP
#define OPENDRIVE_HDMAPTESTS_HPP

#include "gtest/gtest.h"
#include "OpenDRIVE/HDMap.hpp"

namespace opendrive {
    namespace tests {

        /**
         * Common setup for the tests on the mock HD map.
         */
        class HDMapTests : public ::testing::Test {
        protected:

            /**
             * The HD maps.
             */
            std::shared_ptr<HDMap> testMapOpendrive14;
//            , highwayExitSouth, highwayCenter;

            /**
             * The id of the test roads.
             */
            const char *roadIdTestMapOpendrive14 = "2311000", *roadIdHighwayExitSouth = "1088000";

            /**
             * The test roads.
             */
            Road roadTestMapOpendrive14;

            /**
             * The maximal difference after parsing.
             */
            double maxDifference = 1e-52;

            /**
             * @destructor
             */
            ~HDMapTests() override = default;

            /**
             * @setup
             */
            void SetUp() override;
        };
    }
}


#endif //OPENDRIVE_HDMAPTESTS_HPP
