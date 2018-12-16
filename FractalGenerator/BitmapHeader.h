#pragma once

#include <cstdint>

using namespace std;

// C++ compilers align data with a padding so it will be more efficient in memory but since we will be writing
// this bitmap header to a file we need to specify to the compiler to turn off that padding

#pragma pack(2) //align on 2 byte boundaries ?

namespace CaveOfProgramming
{
	struct BitmapFileHeader
	{
		char header[2]{ 'B', 'M' };
		int32_t fileSize; // size of the final file. This has to be exactly 32bit so it depends on the machine. To ensure portability we use int32_t
		int32_t reserved{ 0 };
		int32_t dataOffset;
	};

	struct BitmapInfoHeader
	{
		int32_t headerSize{ 40 };
		int32_t width;
		int32_t height;
		int16_t planes{ 1 };
		int16_t bitsPerPixel{ 24 };
		int32_t compression{ 0 };
		int32_t dataSize{ 0 };
		int32_t horizontalResolution{ 2400 };
		int32_t verticalResolution{ 2400 };
		int32_t colors{ 0 };
		int32_t importantColors{ 0 };
	};
}

