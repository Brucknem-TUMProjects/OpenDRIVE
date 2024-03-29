//
// Created by brucknem on 23.06.21.
//

#ifndef OPENDRIVE_ELEVATION_HPP
#define OPENDRIVE_ELEVATION_HPP

#include "OpenDRIVE/CubicPolynomWrapper.hpp"

namespace opendrive {

    /**
     * Wrapper for the OpenDRIVE elevation class.
     *
     * https://www.asam.net/index.php?eID=dumpFile&t=f&f=3495&token=56b15ffd9dfe23ad8f759523c806fc1f1a90a0e8#_methods_of_elevation
     */
    class Elevation : public opendrive::CubicPolynomWrapper {
    public:

        /**
         * @constructor
         */
        explicit Elevation() = default;

        /**
         * @constructor
         */
        Elevation(double s, const CubicPolynom &polynom);


        /**
         * @destructor
         */
        ~Elevation() override = default;
    };
}

#endif //OPENDRIVE_ELEVATION_HPP
