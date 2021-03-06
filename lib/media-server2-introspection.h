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

#ifndef _MEDIA_SERVER2_INTROSPECTION_H_
#define _MEDIA_SERVER2_INTROSPECTION_H_

#define INTROSPECTION_OPEN                                      \
  "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"                  \
  "<node>"                                                      \
  "  <!-- http://live.gnome.org/Rygel/MediaServer2Spec -->"

#define INTROSPECTION_CLOSE                     \
  "</node>"

#define MEDIAOBJECT2_IFACE                                              \
  "  <interface name=\"org.gnome.UPnP.MediaObject2\">"                  \
  "    <property name=\"Parent\"      type=\"o\" access=\"read\"/>"     \
  "    <property name=\"Type\"        type=\"s\" access=\"read\"/>"     \
  "    <property name=\"Path\"        type=\"o\" access=\"read\"/>"     \
  "    <property name=\"DisplayName\" type=\"s\" access=\"read\"/>"     \
  "  </interface>"

#define MEDIAITEM2_IFACE                                                \
  "  <interface name=\"org.gnome.UPnP.MediaItem2\">"                    \
  "    <property name=\"URLs\"           type=\"as\" access=\"read\"/>" \
  "    <property name=\"MIMEType\"       type=\"s\"  access=\"read\"/>" \
  "    <property name=\"Size\"           type=\"x\"  access=\"read\"/>" \
  "    <property name=\"Artist\"         type=\"s\"  access=\"read\"/>" \
  "    <property name=\"Album\"          type=\"s\"  access=\"read\"/>" \
  "    <property name=\"Date\"           type=\"s\"  access=\"read\"/>" \
  "    <property name=\"Genre\"          type=\"s\"  access=\"read\"/>" \
  "    <property name=\"DLNAProfile\"    type=\"s\"  access=\"read\"/>" \
  "    <property name=\"Duration\"       type=\"i\"  access=\"read\"/>" \
  "    <property name=\"Bitrate\"        type=\"i\"  access=\"read\"/>" \
  "    <property name=\"SampleRate\"     type=\"i\"  access=\"read\"/>" \
  "    <property name=\"BitsPerSample\"  type=\"i\"  access=\"read\"/>" \
  "    <property name=\"Width\"          type=\"i\"  access=\"read\"/>" \
  "    <property name=\"Height\"         type=\"i\"  access=\"read\"/>" \
  "    <property name=\"ColorDepth\"     type=\"i\"  access=\"read\"/>" \
  "    <property name=\"PixelWidth\"     type=\"i\"  access=\"read\"/>" \
  "    <property name=\"PixelHeight\"    type=\"i\"  access=\"read\"/>" \
  "    <property name=\"Thumbnail\"      type=\"o\"  access=\"read\"/>" \
  "    <property name=\"AlbumArt\"       type=\"o\"  access=\"read\"/>" \
  "  </interface>"

#define MEDIACONTAINER2_IFACE                                           \
  "  <interface name=\"org.gnome.UPnP.MediaContainer2\">"               \
  "    <property name=\"ChildCount\"     type=\"u\"  access=\"read\"/>" \
  "    <property name=\"ItemCount\"      type=\"u\"  access=\"read\"/>" \
  "    <property name=\"ContainerCount\" type=\"u\"  access=\"read\"/>" \
  "    <property name=\"Searchable\"     type=\"b\"  access=\"read\"/>" \
  "    <method name=\"ListChildren\">"                                  \
  "      <arg name=\"offset\"  direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"max\"     direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"filter\"  direction=\"in\"  type=\"as\"/>"         \
  "      <arg name=\"objects\" direction=\"out\" type=\"a(a{sv})\"/>"   \
  "    </method>"                                                       \
  "    <method name=\"ListContainers\">"                                \
  "      <arg name=\"offset\"  direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"max\"     direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"filter\"  direction=\"in\"  type=\"as\"/>"         \
  "      <arg name=\"objects\" direction=\"out\" type=\"a(a{sv})\"/>"   \
  "    </method>"                                                       \
  "    <method name=\"ListItems\">"                                     \
  "      <arg name=\"offset\"  direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"max\"     direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"filter\"  direction=\"in\"  type=\"as\"/>"         \
  "      <arg name=\"objects\" direction=\"out\" type=\"a(a{sv})\"/>"   \
  "    </method>"                                                       \
  "    <method name=\"SearchObjects\">"                                 \
  "      <arg name=\"query\"   direction=\"in\"  type=\"s\"/>"          \
  "      <arg name=\"offset\"  direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"max\"     direction=\"in\"  type=\"u\"/>"          \
  "      <arg name=\"filter\"  direction=\"in\"  type=\"as\"/>"         \
  "      <arg name=\"objects\" direction=\"out\" type=\"a(a{sv})\"/>"   \
  "    </method>"                                                       \
  "   <signal name=\"Updated\"/>"                                       \
  "  </interface>"

#define INTROSPECTABLE_IFACE                                    \
  "  <interface name=\"org.freedesktop.DBus.Introspectable\">"  \
  "    <method name=\"Introspect\">"                            \
  "      <arg name=\"xml_data\" direction=\"out\" type=\"s\"/>" \
  "    </method>"                                               \
  "  </interface>"

#define PROPERTIES_IFACE                                                \
  "  <interface name=\"org.freedesktop.DBus.Properties\">"              \
  "    <method name=\"Get\">"                                           \
  "      <arg name=\"interface\" direction=\"in\"  type=\"s\"/>"        \
  "      <arg name=\"property\"  direction=\"in\"  type=\"s\"/>"        \
  "      <arg name=\"value\"     direction=\"out\" type=\"v\"/>"        \
  "    </method>"                                                       \
  "    <method name=\"GetAll\">"                                        \
  "      <arg name=\"interface\"  direction=\"in\"  type=\"s\"/>"       \
  "      <arg name=\"properties\" direction=\"out\" type=\"a{sv}\"/>"   \
  "    </method>"                                                       \
  "  </interface>"

#define CONTAINER_INTROSPECTION                 \
  INTROSPECTION_OPEN                            \
  MEDIAOBJECT2_IFACE                            \
  MEDIACONTAINER2_IFACE                         \
  INTROSPECTABLE_IFACE                          \
  PROPERTIES_IFACE                              \
  INTROSPECTION_CLOSE

#define ITEM_INTROSPECTION                      \
  INTROSPECTION_OPEN                            \
  MEDIAOBJECT2_IFACE                            \
  MEDIAITEM2_IFACE                              \
  INTROSPECTABLE_IFACE                          \
  PROPERTIES_IFACE                              \
  INTROSPECTION_CLOSE

#endif /* _MEDIA_SERVER2_INTROSPECTION_H_ */
