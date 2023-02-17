#ifndef BOOLEAN_BIT_ARRAY
#define BOOLEAN_BIT_ARRAY

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

struct bit_array {
  /// @brief Contains the array that holds each byte of information
  uint8_t * array;
};

void bit_array_init(struct bit_array * array, uint64_t size);

void bit_array_free(struct bit_array * array);

void bit_array_set_true(struct bit_array * array, uint64_t index);

void bit_array_set_false(struct bit_array * array, uint64_t index);

bool bit_array_get_value(struct bit_array * array, uint64_t index);

#endif  // BOOLEAN_BIT_ARRAY