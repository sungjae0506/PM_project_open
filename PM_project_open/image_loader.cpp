#include "image_loader.h"

static int image_counter = 1;

FIBITMAP* ImageLoader::createBitMap(string filename) {
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename.data(), 0);
	if (format == -1) { // couldn't find image
		exit(-1);
	}
	else if (format == FIF_UNKNOWN) { // couldn't determine file format
		// attemp to get from file extension
		format = FreeImage_GetFIFFromFilename(filename.data());
		if (!FreeImage_FIFSupportsReading(format)) {
			//cout << "Detected image format cannot be read!" << endl;
			exit(-1);
		}
	}
	FIBITMAP* bitmap = FreeImage_Load(format, filename.data());
	int bitsPerPixel = FreeImage_GetBPP(bitmap);
	//cout << "Source image has " << bitsPerPixel << " bits per pixel." << endl;
	FIBITMAP* bitmap32;
	if (bitsPerPixel == 32) {
		//cout << "Skipping conversion." << endl;
		bitmap32 = bitmap;
	}
	else {
		//cout << "Converting to 32-bits." << endl;
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
	}
	return bitmap32;
}

ImageLoader::ImageLoader() {}

void ImageLoader::load(string path, string name)
{
	FIBITMAP* bitmap32 = createBitMap(path);
	GLuint textureID;
	int imageWidth = FreeImage_GetWidth(bitmap32);
	int imageHeight = FreeImage_GetHeight(bitmap32);
	GLubyte* textureData = FreeImage_GetBits(bitmap32);

	glGenTextures(image_counter, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight,
		0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, textureData);

	u_map.insert({name, image_counter});
	++image_counter;
}

void ImageLoader::bind(string name)
{
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, u_map[name]);
}