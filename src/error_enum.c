#include "error_enum.h"

#include <stdio.h>

void show_error(enum error_t error) {
  switch (error) {
    // No error to show
    case ERROR_SUCCESS:
      break;
    // Failed to allocate memory
    case MEMORY_ERROR:
      fprintf(stderr, "Error: could not allocate memory\n");
      break;
  }
}