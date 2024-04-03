/*
SLK_img2pixel - a tool for converting images to pixelart

Written in 2024 by Lukas Holzbeierlein (Captain4LK) email: captain4lk [at] tutanota [dot] com

To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.

You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
*/

//External includes
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "HLH_gui.h"

#include "../../external/tinyfiledialogs.h"
//-------------------------------------

//Internal includes
#include "../img2pixel.h"
#include "../util.h"
//-------------------------------------

//#defines
//-------------------------------------

//Typedefs
//-------------------------------------

//Variables
static char path_image_load[512] = {0};
static char path_palette_load[512] = {0};
static char path_preset_load[512] = {0};
static char path_palette_save[512] = {0};
static char path_preset_save[512] = {0};

static char path_palette[512] = {0};
static char path_preset[512] = {0};
//-------------------------------------

//Function prototypes
//-------------------------------------

//Function implementations

SLK_image32 *image_select()
{
   const char *filter_patterns[2] = {"*.png"};
   const char *file_path = tinyfd_openFileDialog("Select a file",path_image_load,0,filter_patterns,NULL,0);

   if(file_path!=NULL)
      strncpy(path_image_load,file_path,512);


   int width,height;
   uint32_t *data = HLH_gui_image_load(file_path,&width,&height);
   if(data==NULL)
      return NULL;

   SLK_image32 *img32 = malloc(sizeof(*img32)+sizeof(*img32->data)*width*height);
   img32->w = width;
   img32->h = height;
   memcpy(img32->data,data,sizeof(*img32->data)*width*height);
   HLH_gui_image_free(data);

   return img32;
}

const char *palette_load_select()
{
   const char *filter_patterns[] = {"*.pal","*.png","*.gpl","*.hex"};
   const char *file_path = tinyfd_openFileDialog("Load a palette",path_palette_load,4,filter_patterns,NULL,0);

   memset(path_palette,0,sizeof(path_palette));
   if(file_path!=NULL)
      strncpy(path_palette,file_path,511);

   return path_palette;
}

const char *preset_load_select()
{
   const char *filter_patterns[2] = {"*.json"};
   const char *file_path = tinyfd_openFileDialog("Select a preset",path_preset_load,1,filter_patterns,NULL,0);

   memset(path_preset,0,sizeof(path_preset));
   if(file_path!=NULL)
      strncpy(path_preset,file_path,511);

   return path_preset;
}

const char *palette_save_select()
{
}

const char *preset_save_select()
{
   const char *filter_patterns[2] = {"*.json"};
   const char *file_path = tinyfd_saveFileDialog("Save preset",path_preset_save,1,filter_patterns,NULL);

   memset(path_preset,0,sizeof(path_preset));
   if(file_path!=NULL)
      strncpy(path_preset,file_path,511);

   return path_preset;
}
//-------------------------------------
