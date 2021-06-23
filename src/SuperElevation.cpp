//
// Created by brucknem on 23.06.21.
//

#include "OpenDRIVE/SuperElevation.hpp"

namespace opendrive {

    SuperElevation::SuperElevation(const superelevation &openDriveObject) : ElevationBase(
            openDriveObject.s().get(),
            openDriveObject.a().get(),
            openDriveObject.b().get(),
            openDriveObject.c().get(),
            openDriveObject.d().get()
    ) {}
}