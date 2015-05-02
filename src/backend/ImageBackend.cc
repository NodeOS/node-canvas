#include "ImageBackend.h"

ImageBackend::ImageBackend(int width, int height) {
  this->name = "image";

  this->width = width;
  this->height = height;
}

cairo_surface_t *ImageBackend::createSurface() {
  this->surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, this->width, this->height);
  //NanAdjustExternalMemory(4 * this->width * this->height);
  return this->surface;
}

cairo_surface_t *ImageBackend::recreateSurface() {
  if (this->surface != NULL) {
    //int old_width = cairo_image_surface_get_width(this->surface);
    //int old_height = cairo_image_surface_get_height(this->surface);
    cairo_surface_destroy(this->surface);
    //NanAdjustExternalMemory(-4 * old_width * old_height);
  }
  this->surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  //NanAdjustExternalMemory(4 * (width * height - old_width * old_height));
  return this->surface;
}

void ImageBackend::destroySurface() {
  if (this->surface != NULL) {
    cairo_surface_destroy(this->surface);
    //NanAdjustExternalMemory(-4 * this->width * this->height);
  }
}