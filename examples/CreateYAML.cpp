#include <OpenDRIVE/HDMapFactory.hpp>
#include "OpenDRIVE/HDMap.hpp"
#include "OpenDRIVE/utils/Formatter.hpp"

/**
 * An example executable to print some google maps links for the geometries and objects along a road.
 */
int main(int argc, char **argv) {
    auto highwayExitSouth = opendrive::createHDMap("../misc/highway_exit_south.xodr");

    opendrive::writeToFile("objects.csv", opendrive::objectsToYAML(highwayExitSouth));
}
