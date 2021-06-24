//
// Created by brucknem on 22.02.21.
//

#include <OpenDRIVE/HDMapFactory.hpp>
#include "OpenDriveTests.hpp"

namespace opendrive {
    namespace tests {

        std::map<double, opendrive::Geometry> createMockPlanView() {
            return {
                    {0.000000000000e+00,
                            {
                                    0.000000000000e+00,
                                    {6.961205248677e+05, 5.347042677392e+06},
                                    4.423314246392e+00,
                                    2.874078777576e+02,
                                    {-0.000000000000e+00, 1.000000000000e+00, -2.864238929279e-11, 9.895389049440e-14},
                                    {0.000000000000e+00, 2.775557561563e-16,  -1.284829717715e-07, 3.576738398807e-10}
                            }
                    },
                    {2.874078777576e+02,
                            {
                                    2.874078777576e+02,
                                    {6.960385927716e+05, 5.346767195233e+06},
                                    4.423329027461e+00,
                                    5.748157887767e+02,
                                    {-0.000000000000e+00, 1.000000008167e+00, 5.933728519558e-11,  -2.430509865365e-13},
                                    {0.000000000000e+00, -5.551115123126e-17, 1.799118651202e-07,  3.576734045230e-10,}
                            }
                    },
                    {
                     8.622236665343e+02,
                            {
                                    8.622236665343e+02,
                                    {6.958748628798e+05, 5.346216190964e+06},
                                    4.423890399888e+00,
                                    5.748158546725e+02,
                                    {-0.000000000000e+00, 9.999999930307e-01, 8.745456108497e-11,  -1.626631700872e-13},
                                    {0.000000000000e+00, 3.330669073875e-16,  7.967009019975e-07,  -1.286803903583e-09}
                            }
                    },
                    {1.437039521207e+03,
                            {
                                    1.437039521207e+03,
                                    {6.957113382597e+05, 5.345665125669e+06},
                                    4.423530781255e+00,
                                    2.874078170873e+02,
                                    {-0.000000000000e+00, 9.999999969958e-01, 3.184450120314e-10,  -3.332438972207e-12},
                                    {0.000000000000e+00, 1.110223024625e-16,  -1.422324932357e-06, -1.286804999320e-09,}
                            }
                    }
            };
        }


        std::map<double, opendrive::Elevation> createMockElevationProfile() {
            return {
                    {0.000000000000e+00, {0.000000000000e+00, {5.299890546737e+02, 1.580599780197e-03, -1.160874186427e-05, 6.476066427343e-08}}},
                    {1.285999579869e+02, {1.285999579869e+02, {5.301380666136e+02, 1.807858074760e-03, 1.337591425002e-05,  -4.759366261012e-08}}},
                    {2.728993017151e+02, {2.728993017151e+02, {5.305344546271e+02, 2.695100722222e-03, -7.227288590766e-06, 2.892125591712e-08}}},
                    {3.938991985649e+02, {3.938991985649e+02, {5.308059826226e+02, 2.216404532070e-03, 3.271118357447e-06,  -4.122192376141e-09}}},
                    {6.674980509018e+02, {6.674980509018e+02, {5.315728272806e+02, 3.080636385751e-03, -1.123629522267e-07, -1.503132638826e-08}}},
                    {7.953974590946e+02, {7.953974590946e+02, {5.319335520736e+02, 2.314235102362e-03, -5.879856200454e-06, 2.283249834106e-07}}},
                    {8.622238689487e+02, {8.622238689487e+02, {5.321300853418e+02, 4.587315677193e-03, 3.989456056352e-05,  -4.897087110523e-07}}},
                    {9.303965505984e+02, {9.303965505984e+02, {5.324730693641e+02, 3.198968990467e-03, -6.025970761551e-05, 4.648519809068e-07}}},
                    {9.974962338670e+02, {9.974962338670e+02, {5.325568430599e+02, 1.390957746856e-03, 3.331455444131e-05,  -1.605512541194e-07}}},
                    {1.083595681573e+03, {1.083595681573e+03, {5.328210941115e+02, 3.557132542687e-03, -8.155568483286e-06, 1.841840849269e-08}}},
                    {1.273395587566e+03, {1.273395587566e+03, {5.333283744533e+02, 2.451794760839e-03, 2.331868118082e-06,  -8.779862637743e-09}}},
                    {1.447594347269e+03, {1.447594347269e+03, {5.337798238718e+02, 2.464931558007e-03, -2.256455427488e-06, 3.094061046700e-09}}}
            };
        }

        std::map<double, opendrive::SuperElevation> createMockLateralProfile() {
            return {
                    {0.000000000000e+00, {0.000000000000e+00, {3.192305336358e-02, -7.543093979616e-05, -4.921087190205e-08, 1.391947694799e-09}}},
                    {1.443000000201e+02, {1.443000000201e+02, {2.419604064954e-02, -2.681746538422e-06, 5.533632852603e-07,  -2.399473526998e-09}}},
                    {2.971999998717e+02, {2.971999998717e+02, {2.814569594099e-02, -1.750881438284e-06, -5.472752205053e-07, 2.289859574847e-09}}},
                    {4.343999993339e+02, {4.343999993339e+02, {2.351751580865e-02, -2.261135159190e-05, 3.952309768071e-07,  -1.025974983558e-09}}},
                    {6.288999994281e+02, {6.288999994281e+02, {2.652218745708e-02, 1.469482798241e-05,  -2.034254263894e-07, 4.608928484333e-10}}},
                    {8.622236687793e+02, {8.622236687793e+02, {2.473069043691e-02, -4.960176177732e-06, 1.191862053331e-07,  -3.222259809893e-10}}},
                    {1.062899999858e+03, {1.062899999858e+03, {2.593099878858e-02, 3.946446990718e-06,  -7.480317759592e-08, 1.859146408603e-10}}},
                    {1.362500000091e+03, {1.362500000091e+03, {2.539865240145e-02, 9.187566748192e-06,  9.229690173944e-08,  -4.355871875649e-10}}},
                    {1.574499999681e+03, {1.574499999681e+03, {2.734427802983e-02, -1.040963843669e-05, -1.847365490166e-07, 2.676288794460e-09}}}
            };
        }

        std::map<std::string, opendrive::Object> createMockObjects() {
            return
                    {
                            {"4007951", {1.3107, -18.002, "pole", "permanentDelineator", "4007951", 0.8284, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.5555}},
                            {"4007952", {50.913, -17.782, "pole", "permanentDelineator", "4007952", 0.8034, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.4685}},
                            {"4007953", {100.92, -17.77,  "pole", "permanentDelineator", "4007953", 0.7705, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.4215}},
                            {"4007954", {150.71, -17.54,  "pole", "permanentDelineator", "4007954", 0.7472, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.4062}},
                            {"4007955", {200.21, -17.236, "pole", "permanentDelineator", "4007955", 1.094,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4135}},
                            {"4007956", {250.1,  -17.284, "pole", "permanentDelineator", "4007956", 1.111,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4477}},
                            {"4007957", {299.94, -17.413, "pole", "permanentDelineator", "4007957", 1.091,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4769}},
                            {"4007958", {349.55, -18.087, "pole", "permanentDelineator", "4007958", 1.141,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4527}},
                            {"4007959", {399.4,  -20.57,  "pole", "permanentDelineator", "4007959", 1.136,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4995}},
                            {"4007960", {449.1,  -20.52,  "pole", "permanentDelineator", "4007960", 1.152,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4783}},
                            {"4007961", {498.19, -20.475, "pole", "permanentDelineator", "4007961", 1.092,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4979}},
                            {"4007962", {548.17, -20.603, "pole", "permanentDelineator", "4007962", 1.094,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5246}},
                            {"4007963", {600.38, -20.682, "pole", "permanentDelineator", "4007963", 1.201,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5546}},
                            {"4007964", {641.98, -20.711, "pole", "permanentDelineator", "4007964", 1.052,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5534}},
                            {"4007965", {700.3,  -20.877, "pole", "permanentDelineator", "4007965", 0.8486, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.528}},
                            {"4007966", {750.12, -20.783, "pole", "permanentDelineator", "4007966", 0.8236, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.5088}},
                            {"4007967", {799.78, -20.569, "pole", "permanentDelineator", "4007967", 1.124,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5205}},
                            {"4007968", {849.7,  -20.606, "pole", "permanentDelineator", "4007968", 1.087,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5124}},
                            {"4007969", {899.4,  -20.677, "pole", "permanentDelineator", "4007969", 1.052,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4987}},
                            {"4007970", {949.16, -20.795, "pole", "permanentDelineator", "4007970", 1.147,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.4982}},
                            {"4007971", {998.97, -20.656, "pole", "permanentDelineator", "4007971", 1.112,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5185}},
                            {"4007972", {1049.2, -20.722, "pole", "permanentDelineator", "4007972", 1.073,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5576}},
                            {"4007973", {1100.7, -20.914, "pole", "permanentDelineator", "4007973", 0.8239, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.5156}},
                            {"4007974", {1150.4, -20.907, "pole", "permanentDelineator", "4007974", 0.7901, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.4936}},
                            {"4007975", {1200.3, -20.992, "pole", "permanentDelineator", "4007975", 0.7455, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.507}},
                            {"4007976", {1250.1, -21.03,  "pole", "permanentDelineator", "4007976", 0.8126, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.5112}},
                            {"4007977", {1300,   -20.978, "pole", "permanentDelineator", "4007977", 0.7362, 0, 0, "none", 0, 0, 0, 0, 0.05, -0.5233}},
                            {"4007978", {1350,   -20.952, "pole", "permanentDelineator", "4007978", 0.743,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5213}},
                            {"4007979", {1399.7, -20.897, "pole", "permanentDelineator", "4007979", 1.183,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5248}},
                            {"4007980", {1449.4, -20.705, "pole", "permanentDelineator", "4007980", 1.179,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5477}},
                            {"4007981", {1499.2, -20.476, "pole", "permanentDelineator", "4007981", 1.231,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5636}},
                            {"4007982", {1548.8, -20.449, "pole", "permanentDelineator", "4007982", 1.19,   0, 0, "none", 0, 0, 0, 0, 0.05, -0.5312}},
                            {"4007983", {1600.6, -20.505, "pole", "permanentDelineator", "4007983", 1.192,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5322}},
                            {"4007984", {1650.4, -20.535, "pole", "permanentDelineator", "4007984", 1.164,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5358}},
                            {"4007985", {1700,   -20.435, "pole", "permanentDelineator", "4007985", 1.195,  0, 0, "none", 0, 0, 0, 0, 0.05, -0.5715}}
                    };
        }

        void OpenDriveTests::SetUp() {
            roadTestMapOpenDrive14 = opendrive::Road("0", "test", 1.724447338294e+03, "-1", {{0, "motorway"}},
                                                     createMockObjects(),
                                                     createMockPlanView(), createMockElevationProfile(),
                                                     createMockLateralProfile());

            testMapOpenDrive14 = std::make_shared<opendrive::HDMap>(
                    opendrive::HDMap{
                            "test.xodr",
                            {{"", roadTestMapOpenDrive14}},
                            {
                                    "+proj=tmerc +lat_0=0 +lon_0=9 +k=0.9996 +x_0=500000 +y_0=0 +datum=WGS84 +units=m +no_defs",
                                    "3D Mapping Solutions",
                                    5.350576134016e+06,
                                    5.350576134016e+06,
                                    5.350576134016e+06,
                                    5.350576134016e+06
                            }
                    }
            );
        }
    }
}