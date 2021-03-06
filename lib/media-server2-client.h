/*
 * Copyright (C) 2010 Igalia S.L.
 *
 * Authors: Juan A. Suarez Romero <jasuarez@igalia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef _MEDIA_SERVER2_CLIENT_H_
#define _MEDIA_SERVER2_CLIENT_H_

#include <glib-object.h>
#include <glib.h>
#include <gio/gio.h>

#include "media-server2-common.h"

#define MS2_TYPE_CLIENT                         \
  (ms2_client_get_type ())

#define MS2_CLIENT(obj)                         \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj),           \
                               MS2_TYPE_CLIENT, \
                               MS2Client))

#define MS2_IS_CLIENT(obj)                              \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj),                   \
                               MS2_TYPE_CLIENT))

#define MS2_CLIENT_CLASS(klass)                 \
  (G_TYPE_CHECK_CLASS_CAST((klass),             \
                           MS2_TYPE_CLIENT,     \
                           MS2ClientClass))

#define MS2_IS_CLIENT_CLASS(klass)              \
  (G_TYPE_CHECK_CLASS_TYPE((klass),             \
                           MS2_TYPE_CLIENT))

#define MS2_CLIENT_GET_CLASS(obj)               \
  (G_TYPE_INSTANCE_GET_CLASS ((obj),            \
                              MS2_TYPE_CLIENT,  \
                              MS2ClientClass))

typedef struct _MS2Client        MS2Client;
typedef struct _MS2ClientPrivate MS2ClientPrivate;

struct _MS2Client {

  GObject parent;

  /*< private >*/
  MS2ClientPrivate *priv;
};

typedef struct _MS2ClientClass MS2ClientClass;

struct _MS2ClientClass {

  GObjectClass parent_class;

  void (*updated) (MS2Client *client,
                   const gchar *id);

  void (*destroy) (MS2Client *client);
};

GType ms2_client_get_type (void);

gchar **ms2_client_get_providers (void);

MS2Client *ms2_client_new (const gchar *provider);

const gchar *ms2_client_get_provider_name (MS2Client *client);

void ms2_client_get_properties_async (MS2Client *client,
                                      const gchar *object_path,
                                      gchar **properties,
                                      GAsyncReadyCallback callback,
                                      gpointer user_data);

GHashTable *ms2_client_get_properties_finish (MS2Client *client,
                                              GAsyncResult *res,
                                              GError **error);

GHashTable *ms2_client_get_properties (MS2Client *client,
                                       const gchar *object_path,
                                       gchar **properties,
                                       GError **error);

void ms2_client_list_children_async (MS2Client *client,
                                     const gchar *object_path,
                                     guint offset,
                                     guint max_count,
                                     gchar **properties,
                                     GAsyncReadyCallback callback,
                                     gpointer user_data);

GList *ms2_client_list_children_finish (MS2Client *client,
                                        GAsyncResult *res,
                                        GError **error);

GList *ms2_client_list_children (MS2Client *client,
                                 const gchar *object_path,
                                 guint offset,
                                 guint max_count,
                                 gchar **properties,
                                 GError **error);

void ms2_client_list_containers_async (MS2Client *client,
                                       const gchar *object_path,
                                       guint offset,
                                       guint max_count,
                                       gchar **properties,
                                       GAsyncReadyCallback callback,
                                       gpointer user_data);

GList *ms2_client_list_containers_finish (MS2Client *client,
                                          GAsyncResult *res,
                                          GError **error);

GList *ms2_client_list_containers (MS2Client *client,
                                   const gchar *object_path,
                                   guint offset,
                                   guint max_count,
                                   gchar **properties,
                                   GError **error);

void ms2_client_list_items_async (MS2Client *client,
                                  const gchar *object_path,
                                  guint offset,
                                  guint max_count,
                                  gchar **properties,
                                  GAsyncReadyCallback callback,
                                  gpointer user_data);

GList *ms2_client_list_items_finish (MS2Client *client,
                                     GAsyncResult *res,
                                     GError **error);

GList *ms2_client_list_items (MS2Client *client,
                              const gchar *object_path,
                              guint offset,
                              guint max_count,
                              gchar **properties,
                              GError **error);

GList *ms2_client_search_objects (MS2Client *client,
                                  const gchar *object_path,
                                  const gchar *query,
                                  guint offset,
                                  guint max_count,
                                  gchar **properties,
                                  GError **error);

void ms2_client_search_objects_async (MS2Client *client,
                                      const gchar *object_path,
                                      const gchar *query,
                                      guint offset,
                                      guint max_count,
                                      gchar **properties,
                                      GAsyncReadyCallback callback,
                                      gpointer user_data);

GList *ms2_client_search_objects_finish (MS2Client *client,
                                         GAsyncResult *res,
                                         GError **error);

const gchar *ms2_client_get_root_path (MS2Client *client);

const gchar *ms2_client_get_path (GHashTable *properties);

const gchar *ms2_client_get_parent (GHashTable *properties);

const gchar *ms2_client_get_display_name (GHashTable *properties);

MS2ItemType ms2_client_get_item_type (GHashTable *properties);

const gchar *ms2_client_get_item_type_string (GHashTable *properties);

const gchar *ms2_client_get_mime_type (GHashTable *properties);

const gchar *ms2_client_get_artist (GHashTable *properties);

const gchar *ms2_client_get_album (GHashTable *properties);

const gchar *ms2_client_get_date (GHashTable *properties);

const gchar *ms2_client_get_dlna_profile (GHashTable *properties);

const gchar *ms2_client_get_thumbnail (GHashTable *properties);

const gchar *ms2_client_get_album_art (GHashTable *properties);

const gchar *ms2_client_get_genre (GHashTable *properties);

gint64  ms2_client_get_size (GHashTable *properties);

gint  ms2_client_get_duration (GHashTable *properties);

gint  ms2_client_get_bitrate (GHashTable *properties);

gint  ms2_client_get_sample_rate (GHashTable *properties);

gint  ms2_client_get_bits_per_sample (GHashTable *properties);

gint  ms2_client_get_width (GHashTable *properties);

gint ms2_client_get_height (GHashTable *properties);

gint ms2_client_get_color_depth (GHashTable *properties);

gint ms2_client_get_pixel_width (GHashTable *properties);

gint ms2_client_get_pixel_height (GHashTable *properties);

gchar **ms2_client_get_urls (GHashTable *properties);

gboolean ms2_client_get_searchable (GHashTable *properties);

guint ms2_client_get_child_count (GHashTable *properties);

guint ms2_client_get_item_count (GHashTable *properties);

guint ms2_client_get_container_count (GHashTable *properties);

#endif /* _MEDIA_SERVER2_CLIENT_H_ */
