#ifndef BOOLEAN_BIT_ARRAY
#define BOOLEAN_BIT_ARRAY

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

struct bit_array {
  /// @brief Contains the array that holds each byte of information
  uint8_t * array;
};

/**
 * @brief Initializes every value in the bit array as false
 * 
 * @param array Pointer to the struct holding the array
 * @param byte_amount Amount of bytes to allocate for the array
 */
void bit_array_init(struct bit_array * array, uint64_t byte_amount);

/**
 * @brief Free the memory allocated by the bit array
 * 
 * @param array Pointer to the struct holding the array
 */
void bit_array_free(struct bit_array * array);

/**
 * @brief Set true the bit corresponding to the desired index
 * 
 * @param array Pointer to the struct holding the array
 * @param index Desired position to set true
 */
void bit_array_set_true(struct bit_array * array, uint64_t index);

/**
 * @brief Set false the bit corresponding to the desired index
 * 
 * @param array Pointer to the struct holding the array
 * @param index Desired position to set false
 */
void bit_array_set_false(struct bit_array * array, uint64_t index);

/**
 * @brief Returns the corresponding value in the desired position
 * 
 * @param array Pointer to the struct holding the array
 * @param index Desired position
 * @return true If the value is set to true
 * @return false If the value is set to false
 */
bool bit_array_get_value(struct bit_array * array, uint64_t index);

#endif  // BOOLEAN_BIT_ARRAY