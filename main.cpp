#include <iostream>
#include <vector>

#include "noiseshape.hpp"

using namespace std;

namespace
{
    // Biquad IIR noise shape coefficients
    const double ddr_ns_coeffs[] = {
        // b1 b2         a1                  a2
        -2, 1, -1.8855226352403955, 0.93322959122240612, // Section 1
        -2, 1, -1.772936833863034, 0.81779517600709717,  // Section 2
        -2, 1, -1.6872371309408534, 0.72992712364239787, // ...
        -2, 1, -1.6299927622374928, 0.67123437424770627,
        -2, 1, -1.6014281855331618, 0.641947064769974}; // Section 5

    const int ddr_ns_soscount = sizeof(ddr_ns_coeffs) / (sizeof(ddr_ns_coeffs[0]) * 4);
}

int main(int argc, char *argv[])
{
    const int dsdBlockSize = 4096;
    const int pcmBlockSize = dsdBlockSize / 2;
    const int bits = 24;
    int channelsNum = 2;
    int bytespersample = bits == 20 ? 3 : bits / 8;
    vector<unsigned char> pcmData(pcmBlockSize * channelsNum * bytespersample);
    vector<unsigned char> dsdData(dsdBlockSize * channelsNum);
    char *const pcmIn = reinterpret_cast<char *>(&pcmData[0]);
    char *const dsdOut = reinterpret_cast<char *>(&dsdData[0]);

    while (cin.read(pcmIn, pcmBlockSize * channelsNum))
    {
        for (int c = 0; c < channelsNum; ++c)
        {
            // TODO: implement
        }
    }
}