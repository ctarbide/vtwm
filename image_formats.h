#ifndef _VTWM_IMAGE_FORMATS_H
#define _VTWM_IMAGE_FORMATS_H

#define IMAGE_TYPE_NONE 0
#define IMAGE_TYPE_XPM 1
#define IMAGE_TYPE_PNG 2


typedef struct _Image
{
  int type;
  Pixmap pixmap;
  Pixmap mask;
  char *data;
  int width;
  int height;
  struct _Image *next;
} Image;


#endif
