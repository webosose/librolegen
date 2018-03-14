# Copyright (c) 2010-2018 LG Electronics, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 2.8.7)

project(rolegen CXX)

include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC4)
webos_component(2 1 0)

include(FindPkgConfig)

pkg_check_modules(GLIB2 REQUIRED glib-2.0)
include_directories(${GLIB2_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${GLIB2_CFLAGS_OTHER})

webos_build_pkgconfig()

include_directories(include/public)
webos_add_compiler_flags(ALL -Wall)
webos_add_linker_options(ALL --no-undefined)

webos_configure_source_files(sourcelist src/rolegen.cpp)
add_library(rolegen SHARED ${sourcelist})
target_link_libraries(rolegen ${GLIB2_LDFLAGS})

webos_build_library()

file(GLOB SOURCE_FILES templates/*.*)
install(FILES ${SOURCE_FILES} DESTINATION ${WEBOS_INSTALL_DATADIR}/rolegen/templates)

add_subdirectory(test/securityissues)
