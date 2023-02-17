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
  assert(array);
  /*
    Contains the masks for each index in the array
    128 = 1000 0000
    64 = 0100 0000
    32 = 0010 0000
    16 = 0001 0000
    8 = 0000 1000
    4 = 0000 0100
    2 = 0000 0010
    1 = 0000 0001
  */
  uint8_t masks[] = {128, 64, 32, 16, 8, 4, 2, 1};

  // Divides index by 8
  // This specifies which position of the array is desired
  uint64_t array_index = index >> 3;
  // index % 8 specifies which position inside the byte is desired
  // index & 7 is the same as index % 8
  uint64_t bit_index = index & 7;
  // Sets the value to true with an or
  array->values[array_index] = array->values[array_index] | masks[bit_index];

  return ERROR_SUCCESS;
}

enum error_t bit_array_set_false(struct bit_array * array, uint64_t index) {
  assert(array);
  // See set true for mask explanation
  uint8_t masks[] = {128, 64, 32, 16, 8, 4, 2, 1};
  // Divides index by 8
  // This specifies which position of the array is desired
  uint64_t array_index = index >> 3;
  // index % 8 specifies which position inside the byte is desired
  // index & 7 is the same as index % 8
  uint64_t bit_index = index & 7;

  // If the value is set to true
  if ((masks[bit_index] & array->values[array_index]) > 0) {
    // Substract the desired value to set value to false
    array->values[array_index] = array->values[array_index] - masks[bit_index];
  }

  return ERROR_SUCCESS;
}

bool bit_array_get_value(struct bit_array * array, uint64_t index) {
  assert(array);
  // Assume false
  bool answer = false;
  // See set true for mask explanation
  uint8_t masks[] = {128, 64, 32, 16, 8, 4, 2, 1};
  // Divides index by 8
  // This specifies which position of the array is desired
  uint64_t array_index = index >> 3;
  // index % 8 specifies which position inside the byte is desired
  // index & 7 is the same as index % 8
  uint64_t bit_index = index & 7;

  // If the value is set to true
  if ((masks[bit_index] & array->values[array_index]) > 0) {
    answer = true;
  }

  return answer;
}