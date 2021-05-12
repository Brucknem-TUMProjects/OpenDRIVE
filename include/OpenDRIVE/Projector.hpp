//
// Created by brucknem on 24.02.21.
//

#ifndef OPENDRIVE_PROJECTOR_HPP
#define OPENDRIVE_PROJECTOR_HPP

#include <cstdio>
#include <proj.h>
#include <string>
#include "Vector.hpp"

namespace opendrive {

    /**
     * A projector from a given PROJ projection to [longitude, latitude] coordinates.
     */
    class Projector {
    private:

        /**
         * The projection context. Used for multithreading.
         */
        PJ_CONTEXT *context;

        /**
         * The actual projection algorithm.
         */
        PJ *projection;

    public:

        /**
         * @constructor
         *
         * @param projectionString Projection string adhering to the PROJ rules.
         *
         * @see https://proj.org/usage/quickstart.html
         */
        explicit Projector(const std::string &fromProjection, const std::string &toProjection);

        /**
         * @destructor
         */
        virtual ~Projector();

        /**
         * Projects a vector from a coordinate system to another.
         *
         * @param vector The vector in the original coordinate frame that gets projected.
         * @return  The projected [longitude, latitude] coordinate.
         */
        Vector project(const Vector &vector, PJ_DIRECTION direction = PJ_FWD) const;


    };

    class LongLatProjector : public Projector {
    public:

        /**
         * @constructor
         *
         * @param projectionString Projection string adhering to the PROJ rules.
         *
         * @see https://proj.org/usage/quickstart.html
         */
        explicit LongLatProjector(const std::string &fromProjection);

        static std::string toGoogleMapsLink(const Vector &vector);
    };

    class CartesianProjector : public Projector {
    public:

        /**
         * @constructor
         *
         * @param projectionString Projection string adhering to the PROJ rules.
         *
         * @see https://proj.org/usage/quickstart.html
         */
        explicit CartesianProjector(const std::string &fromProjection);
    };

    class EqualAreaProjector : public Projector {
    public:

        /**
         * @constructor
         *
         * @param projectionString Projection string adhering to the PROJ rules.
         *
         * @see https://proj.org/usage/quickstart.html
         */
        explicit EqualAreaProjector(const std::string &fromProjection);
    };

    class MollweideProjector : public Projector {
    public:

        /**
         * @constructor
         *
         * @param projectionString Projection string adhering to the PROJ rules.
         *
         * @see https://proj.org/usage/quickstart.html
         */
        explicit MollweideProjector(const std::string &fromProjection);
    };
}


#endif //OPENDRIVE_PROJECTOR_HPP