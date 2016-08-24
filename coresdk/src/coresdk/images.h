//
//  images.hpp
//  splashkit
//
//  Created by Andrew Cain on 24/07/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#ifndef images_hpp
#define images_hpp

#include "drawing_options.h"
#include "types.h"

#include <string>
using namespace std;

/// Loads and returns a bitmap. The supplied ``filename`` is used to
/// locate the Bitmap to load. The supplied ``name`` indicates the
/// name to use to refer to this Bitmap in SwinGame. The `Bitmap` can then be
/// retrieved by passing this ``name`` to the `BitmapNamed` function.
///
/// @lib
/// @sn loadBitmapNamed:%s fromFile:%s
///
/// @class Bitmap
/// @constructor
/// @csn initWithName:%s fromFile:%s
bitmap load_bitmap(string name, string filename);

/// Determines if SwinGame has a bitmap loaded for the supplied name.
/// This checks against all bitmaps loaded, those loaded without a name
/// are assigned the filename as a default.
///
bool has_bitmap(string name);

/// Returns the `Bitmap` that has been loaded with the specified name,
/// see `LoadBitmapNamed`.
///
bitmap bitmap_named(string name);

/// Releases the SwinGame resources associated with the bitmap of the
/// specified ``name``.
///
void free_bitmap(bitmap to_delete);

void free_all_bitmaps();

void draw_bitmap(bitmap bmp, float x, float y);

void draw_bitmap(bitmap bmp, float x, float y, drawing_options opts);

void draw_bitmap(string name, float x, float y);

void draw_bitmap(string name, float x, float y, drawing_options opts);

bitmap create_bitmap(string name, int width, int height);

void clear_bitmap(bitmap bmp, color clr);

void clear_bitmap(string name, color clr);

int bitmap_width(bitmap bmp);

int bitmap_width(string name);

int bitmap_height(bitmap bmp);

int bitmap_height(string name);

/**
 *  Returns a rectangle that will encompass the bitmap cell if it were drawn
 *  on at the indicated point.
 *
 * @param src   The bitmap to get the details from
 * @param pt    The point details for the rectangle.
 * @returns     A rectangle at pt, with width and height from the bitmap's cell details.
 */
rectangle bitmap_cell_rectangle(bitmap src, const point_2d &pt);

rectangle bitmap_rectangle_of_cell(bitmap src, int cell);

void bitmap_set_cell_details(bitmap bmp, int width, int height, int columns, int rows, int count);

#endif /* images_hpp */
