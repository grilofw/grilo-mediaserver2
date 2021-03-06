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

#ifndef _MEDIA_SERVER2_PRIVATE_H_
#define _MEDIA_SERVER2_PRIVATE_H_

#include <glib.h>

#include "media-server2-client.h"
#include "media-server2-server.h"

#define MS2_DBUS_SERVICE_PREFIX "org.gnome.UPnP.MediaServer2."
#define MS2_DBUS_PATH_PREFIX    "/org/gnome/UPnP/MediaServer2/"

#define MS2_DBUS_SERVICE_PREFIX_LENGTH 28

void ms2_client_notify_destroy (MS2Client *client);

void ms2_client_notify_updated (MS2Client *client, const gchar *object_path);

void ms2_observer_add_client (MS2Client *client, const gchar *provider);

void ms2_observer_remove_client (MS2Client *client, const gchar *provider);

#endif /* _MEDIA_SERVER2_PRIVATE_H_ */
