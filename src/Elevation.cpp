//
// Created by brucknem on 23.06.21.
//

#include "OpenDRIVE/Elevation.hpp"

namespace opendrive {

    Elevation::Elevation(const elevation &openDriveObject) : ElevationBase(
            openDriveObject.s().get(),
            openDriveObject.a().get(),
            openDriveObject.b().get(),
            openDriveObject.c().get(),
            openDriveObject.d().get()
    ) {}
}