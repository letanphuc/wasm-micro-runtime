/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include <stdio.h>
#include <stdlib.h>

void fibo(int x) {
  uint64_t a = 1;
  uint64_t b = 1;
  for (int i = 2; i < x; i++) {
    const uint64_t n = a + b;
    a = b;
    b = n;

    printf("[%i]: %llu\r\n", i, n);
  }
}

int main(int argc, char **argv) {
  char *buf;

  printf("Hello world from WASM app!\n");

  buf = malloc(1024);
  if (!buf) {
    printf("malloc buf failed\n");
    return -1;
  }

  printf("buf ptr: %p\n", buf);

  snprintf(buf, 1024, "%s", "1234\n");
  printf("buf: %s", buf);

  free(buf);

  fibo(20);

  printf("End of WASM here!!!!\r\n");
  return 0;
}
