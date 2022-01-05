//Your C/C++ code can access files using the normal libc stdio API (fopen, fclose, etc.)
//JavaScript is usually run in the sandboxed environment of a web browser, without direct access to the local file system. Emscripten simulates a file system that you can access from your compiled C/C++ code using the normal libc stdio API.
//Files that you want to access should be preloaded or embedded into the virtual file system. Preloading (or embedding) generates a virtual file system that corresponds to the file system structure at compile time, relative to the current directory.
//The hello_world_file.cpp example shows how to load a file (both the test code and the file to be loaded shown below):

// Copyright 2012 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.

#include <stdio.h>
int main() {
  FILE *file = fopen("tests/hello_world_file.txt", "rb");
  if (!file) {
    printf("cannot open file\n");
    return 1;
  }
  while (!feof(file)) {
    char c = fgetc(file);
    if (c != EOF) {
      putchar(c);
    }
  }
  fclose (file);
  return 0;
}
