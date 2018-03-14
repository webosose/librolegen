// Copyright (c) 2010-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

// NOTE: The header files needed by rolegen.cpp are now included there.
// The ones defined below might be used includers of rolegen.h (this file).
#if 0
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include <string>

using namespace std;

void ndkGenerateRole(string id, string executablePath);
// deprecated
void __attribute__((deprecated)) pdkGenerateRole(string id, string executablePath);
void roleGenerate(string templatePath, string destinationPath, string id, string executablePath);
void tritonGenerateRole(string id);
