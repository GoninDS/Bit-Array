#include "boolean_bit_array.h"

enum error_t bit_array_init(struct bit_array * array, uint64_t byte_amount) {
  // Assume error success
  enum error_t error = ERROR_SUCCESS;
  array->values = (uint8_t*) calloc(byte_amount, sizeof(uint8_t));
  // No memory was allocated
  if (array->values == NULL) {
    array->values = 0;
    error = MEMORY_ERROR;
  }
  return error;
}

enum error_t bit_array_free(struct bit_array * array) {
  assert(array);
  // Free the memory allocated for the array values
  free(array->values);
  return ERROR_SUCCESS;
}

enum error_t bit_array_set_true(struct bit_array * array, uint64_t index) {
  return ERROR_SUCCESS;
}

enum error_t bit_array_set_false(struct bit_array * array, uint64_t index) {
  return ERROR_SUCCESS;
}

bool bit_array_get_value(struct bit_array * array, uint64_t index) {
  return true;
}