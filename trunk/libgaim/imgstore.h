/**
 * @file imgstore.h IM Image Store API
 * @ingroup core
 *
 * gaim
 *
 * Gaim is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifndef _GAIM_IMGSTORE_H_
#define _GAIM_IMGSTORE_H_

struct _GaimStoredImage;
typedef struct _GaimStoredImage GaimStoredImage;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Add an image to the store. The caller owns a reference
 * to the image in the store, and must dereference the image
 * with gaim_imgstore_unref for it to be freed.
 *
 * @param data		Pointer to the image data.
 * @param size		Image data's size.
 * @param filename	Filename associated with image.

 * @return ID for the image.
 */
int gaim_imgstore_add(const void *data, size_t size, const char *filename);

/**
 * Retrieve an image from the store. The caller does not own a
 * reference to the image.
 *
 * @param id		The ID for the image.
 *
 * @return A pointer to the requested image, or NULL if it was not found.
 */
GaimStoredImage *gaim_imgstore_get(int id);

/**
 * Retrieves a pointer to the image's data.
 *
 * @param i	The Image
 *
 * @return A pointer to the data, which must not
 *         be freed or modified.
 */
gpointer gaim_imgstore_get_data(GaimStoredImage *i);

/**
 * Retrieves the length of the image's data.
 *
 * @param i	The Image
 *
 * @return The size of the data that the pointer returned by
 *         gaim_imgstore_get_data points to.
 */
size_t gaim_imgstore_get_size(GaimStoredImage *i);

/**
 * Retrieves a pointer to the image's filename.
 *
 * @param i	The Image
 *
 * @return A pointer to the filename, which must not
 *         be freed or modified.
 */
const char *gaim_imgstore_get_filename(GaimStoredImage *i);

/**
 * Increment the reference count for an image in the store. The
 * image will be removed from the store when the reference count
 * is zero.
 *
 * @param id		The ID for the image.
 */
void gaim_imgstore_ref(int id);

/**
 * Decrement the reference count for an image in the store. The
 * image will be removed from the store when the reference count
 * is zero.
 *
 * @param id		The ID for the image.
 */
void gaim_imgstore_unref(int id);

#ifdef __cplusplus
}
#endif

#endif /* _GAIM_IMGSTORE_H_ */
