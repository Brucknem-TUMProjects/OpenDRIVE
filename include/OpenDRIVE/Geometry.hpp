//
// Created by brucknem on 22.02.21.
//

#ifndef OPENDRIVE_GEOMETRY_HPP
#define OPENDRIVE_GEOMETRY_HPP

#include "OpenDRIVE/OpenDriveWrapper.hpp"
#include "OpenDRIVE/utils/Vector.hpp"
#include "OpenDRIVE/utils/CubicPolynom.hpp"

namespace opendrive {
    /**
     * Wrapper for the OpenDRIVE geometry class.
     *
     * https://www.asam.net/index.php?eID=dumpFile&t=f&f=3495&token=56b15ffd9dfe23ad8f759523c806fc1f1a90a0e8#_geometry
     */
    class Geometry : public OpenDriveWrapper {

    private:

        /**
         * Wrapper for the OpenDRIVE paramPoly3 class.
         *
         * https://www.asam.net/index.php?eID=dumpFile&t=f&f=3495&token=56b15ffd9dfe23ad8f759523c806fc1f1a90a0e8#_parametric_cubic_curve
         */
        class ParamPoly3 {
            /**
             * The polynom to calculate the u ccordinate.
             */
            CubicPolynom u;

            /**
             * The polynom to calculate the v ccordinate.
             */
            CubicPolynom v;

        public:
            /**
             * @constructor
             */
            ParamPoly3(const CubicPolynom &u, const CubicPolynom &v);

            /**
             * @get
             */
            const CubicPolynom &getU() const;

            /**
             * @get
             */
            const CubicPolynom &getV() const;
        };

        std::shared_ptr<ParamPoly3> paramPoly3;

        /**
         * The heading direction of the geometry.
         */
        double heading;

        /**
         * The length of the geometry.
         */
        double length;

        /**
         * The x,y start position of the geometry.
         */
        Vector start;

    protected:

        /**
         * Specific interpolation functions per primitive.
         *
         * @param s The s-coordinate of interest.
         */
        Vector interpolatePrimitive(double s) const;

        /**
         * Specific calculation functions for the s tangent per primitive.
         *
         * @param s The s-coordinate of interest.
         */
        Vector calculatePrimitiveReferenceTangent(double s) const;

        /**
         * Calculates the local s coordinate.
         *
         * @param s The s-coordinate of interest.
         * @return s - s_start
         */
        double getGetLocalS(double s) const;

        /**
         * Calculates the [u, v] coordinate of the primitive at coordinate s in the local reference frame.
         *
         * @param s The s-coordinate of interest.
         */
        Vector getUVCoordinate(double s) const;

    public:

        /**
        * @constructor
        */
        Geometry(double s, const Vector &start, double heading, double length, const CubicPolynom &u,
                 const CubicPolynom &v);

        /**
        * @constructor
        */
        Geometry(double s, const Vector &start, double heading, double length);

        /**
        * @destructor
        */
        ~Geometry() override = default;

        /**
         * @get The start [x, y] coordinate of the geometry, i.e. the offset of the geometry.
         */
        Vector getStart() const;

        /**
         * Interpolates the [x, y] point of the start of the geometry, i.e. at s == 0.
         */
        Vector interpolateStart() const;

        /**
         * Interpolates the [x, y] point of the end of the geometry, i.e. at s == length.
         */
        Vector interpolateEnd() const;

        /**
         * Interpolates the [x, y] point at the given s coordinate along the geometry.
         * @param s s-coordinate of start position
         */
        Vector interpolate(double s) const;

        /**
         * Calculates the s tangent vector of the reference line.
         *
         * @param s s-coordinate of start position
         */
        Vector calculateTangent(double s) const;

        /**
         * Calculates the t normal vector of the reference line.
         *
         * @param s s-coordinate of start position
         */
        Vector calculateNormal(double s) const;

        /**
         * Gets the ending s coordinate, i.e. the start + length.
         * @return
         */
        double getEndSCoordinate() const;

        /**
         * @get
         */
        const std::shared_ptr<ParamPoly3> &getParamPoly3() const;
    };

}

#endif //OPENDRIVE_GEOMETRY_HPP
