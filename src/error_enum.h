#ifndef ERROR_ENUM_H
#define ERROR_ENUM_H

#include <stdlib.h>

enum error_t {
  /// @brief Used in case of not having an error, equals to 0
  ERROR_SUCCESS = EXIT_SUCCESS,
  /// @brief Used in case of having an error allocating memory, equals to 1
  MEMORY_ERROR,
};

/**
 * @brief Shows a message indicating which error was encountered
 * 
 * @param error The error to display
 */
void show_error(enum error_t error);

#endif  // ERROR_ENUM
