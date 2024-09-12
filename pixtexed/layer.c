/*
pixtexed - pixel art editor

Written in 2024 by Lukas Holzbeierlein (Captain4LK) email: captain4lk [at] tutanota [dot] com

To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.

You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
*/

//External includes
#include <stdlib.h>
#include <string.h>
//-------------------------------------

//Internal includes
#include "layer.h"
//-------------------------------------

//#defines
//-------------------------------------

//Typedefs
//-------------------------------------

//Variables
//-------------------------------------

//Function prototypes
//-------------------------------------

//Function implementations

Layer *layer_new(size_t size)
{
   Layer *l = calloc(1,sizeof(*l)+size);

   return l;
}

void layer_free(Layer *layer)
{
   if(layer==NULL)
      return;

   free(layer);
}

void layer_copy(Layer *dst, const Layer *src, size_t size)
{
   memcpy(dst,src,size);
}
//-------------------------------------