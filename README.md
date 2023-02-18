# **Bit-Array**

Array in C to use every bit in an array of bytes as a bool value instead of the C bool data type to optimize memory use.

## **Purpose**

The C data type for a bool takes 1 byte per value. Therefore, if you want to make an array of bool values you will waste seven bits of information per element in the array. Through this struct and the functions provided alongisde it you will be able to optimize memory use by reducing the amount of bits wasted per value.

## **Implementation**

### **Struct and given functions**

The array is of unsigned ints of 8 bits, in other words a byte. Inside every byte each individual bit can be accessed through a bit operation and a corresponding mask to the desired position.

There are five different functions provided to interact with the array inside the struct:

1. **bit_array_init:** Allows the user to initialize every value in the bit array as false. It requires the struct and the amount of bytes desired.

2. **bit_array_free:** Allows the user to free the allocated memory by the bit array.

3. **bit_array_set_true:** Allows the user to set a desired position inside the bits to true. It requires the struct and index (desired bit).

4. **bit_array_set_false:** Allows the user to set a desired position inside the bits to false. It requires the struct and index (desired bit).

5. **bit_array_get_value:** Returns the value of the desired position.

### **Error enumeration and given functions**

Alongside the struct, an error enumeration to handle any possible error is provided. It can return two different values:

1. **ERROR_SUCCESS:** No error was found. Equals to 0.

2. **MEMORY_ERROR:** Used in case of having an error allocating memory. Equals to 1.

It also comes with a function to show in console an error if desired.


