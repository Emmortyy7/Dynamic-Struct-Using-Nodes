#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "DynamicStruct.h"

void print_int8_arr(const int8_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_uint8_arr(const uint8_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%u", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_int16_arr(const int16_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_uint16_arr(const uint16_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%u", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_int32_arr(const int32_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_uint32_arr(const uint32_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%u", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_int64_arr(const int64_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lld", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_uint64_arr(const uint64_t arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%llu", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_signed_char_arr(const signed char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_unsigned_char_arr(const unsigned char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%u", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_signed_int_arr(const signed int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_unsigned_int_arr(const unsigned int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%u", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_signed_short_arr(const signed short arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_unsigned_short_arr(const unsigned short arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%u", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_signed_long_arr(const signed long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%ld", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_unsigned_long_arr(const unsigned long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lu", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_signed_long_long_arr(const signed long long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lld", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_unsigned_long_long_arr(const unsigned long long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%llu", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_char_arr(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_int_arr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_float_arr(const float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_double_arr(const double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.6lf", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_short_arr(const short arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_long_arr(const long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%ld", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void print_long_long_arr(const long long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lld", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void test(NodeHandler *nh) { 
    // Variables
    int8_t int8_t_min = INT8_MIN;
    int8_t int8_t_max = INT8_MAX;
    uint8_t uint8_t_max = UINT8_MAX;
    int16_t int16_t_min = INT16_MIN;
    int16_t int16_t_max = INT16_MAX;
    uint16_t uint16_t_max = UINT16_MAX;
    int32_t int32_t_min = INT32_MIN;
    int32_t int32_t_max = INT32_MAX;
    uint32_t uint32_t_max = UINT32_MAX;
    int64_t int64_t_min = INT64_MIN;
    int64_t int64_t_max = INT64_MAX;
    uint64_t uint64_t_max = UINT64_MAX;
    float float_min = 5.5;
    float float_max = 5.5;
    double double_min = 5.5;
    double double_max = -343.43;
    
    signed char signed_char = -100;
    unsigned char unsigned_char = 200;
    signed int signed_int = -12345;
    unsigned int unsigned_int = 12345;
    signed short signed_short = -1234;
    unsigned short unsigned_short = 1234;
    signed long signed_long = -123456789;
    unsigned long unsigned_long = 123456789;
    signed long long signed_long_long = -1234567890123LL;
    unsigned long long unsigned_long_long = 1234567890123ULL;
    char character = 'A';
    int integer = 123;
    short short_value = 10;
    long long_value = 1000L;
    long long long_long_value = 100000LL;

    // AddVar calls for all types
    AddVar(&int8_t_min, "int8_t_min", INT8_T, nh);
    printf("Var added.\n");
    AddVar(&int8_t_max, "int8_t_max", INT8_T, nh);
    printf("Var added.\n");
    AddVar(&uint8_t_max, "uint8_t_max", UINT8_T, nh);
    printf("Var added.\n");
    AddVar(&int16_t_min, "int16_t_min", INT16_T, nh);
    printf("Var added.\n");
    AddVar(&int16_t_max, "int16_t_max", INT16_T, nh);
    printf("Var added.\n");
    AddVar(&uint16_t_max, "uint16_t_max", UINT16_T, nh);
    printf("Var added.\n");
    AddVar(&int32_t_min, "int32_t_min", INT32_T, nh);
    printf("Var added.\n");
    AddVar(&int32_t_max, "int32_t_max", INT32_T, nh);
    printf("Var added.\n");
    AddVar(&uint32_t_max, "uint32_t_max", UINT32_T, nh);
    printf("Var added.\n");
    AddVar(&int64_t_min, "int64_t_min", INT64_T, nh);
    printf("Var added.\n");
    AddVar(&int64_t_max, "int64_t_max", INT64_T, nh);
    printf("Var added.\n");
    AddVar(&uint64_t_max, "uint64_t_max", UINT64_T, nh);
    printf("Var added.\n");
    AddVar(&signed_char, "signed_char", SIGNED_CHAR, nh);
    printf("Var added.\n");
    AddVar(&unsigned_char, "unsigned_char", UNSIGNED_CHAR, nh);
    printf("Var added.\n");
    AddVar(&signed_int, "signed_int", SIGNED_INT, nh);
    printf("Var added.\n");
    AddVar(&unsigned_int, "unsigned_int", UNSIGNED_INT, nh);
    printf("Var added.\n");
    AddVar(&signed_short, "signed_short", SIGNED_SHORT, nh);
    printf("Var added.\n");
    AddVar(&unsigned_short, "unsigned_short", UNSIGNED_SHORT, nh);
    printf("Var added.\n");
    AddVar(&signed_long, "signed_long", SIGNED_LONG, nh);
    printf("Var added.\n");
    AddVar(&unsigned_long, "unsigned_long", UNSIGNED_LONG, nh);
    printf("Var added.\n");
    AddVar(&signed_long, "signed_long_long", SIGNED_LONG_LONG, nh);
    printf("Var added.\n");
    AddVar(&unsigned_long_long, "unsigned_long_long", UNSIGNED_LONG_LONG, nh);
    printf("Var added.\n");
    AddVar(&character, "character", CHAR, nh);
    printf("Var added.\n");
    AddVar(&integer, "integer", INT, nh);
    printf("Var added.\n");
    AddVar(&short_value, "short_value", SHORT, nh);
    printf("Var added.\n");
    AddVar(&long_value, "long_value", LONG, nh);
    printf("Var added.\n");
    AddVar(&long_long_value, "long_long_value", LONG_LONG, nh);
    printf("Var added.\n");
    AddVar(&float_min, "float_min", FLOAT, nh);
    printf("Var added.\n");
    AddVar(&float_max, "float_max", FLOAT, nh);
    printf("Var added.\n");
    AddVar(&double_min, "double_min", DOUBLE, nh);
    printf("Var added.\n");
    AddVar(&double_max, "double_max", DOUBLE, nh);
    printf("Var added.\n");

    // GetVar and print statements
    printf("int8_t_min: %d\n", *(int8_t *)GetVar("int8_t_min", nh));
    printf("int8_t_max: %d\n", *(int8_t *)GetVar("int8_t_max", nh));
    printf("uint8_t_max: %u\n", *(uint8_t *)GetVar("uint8_t_max", nh));
    printf("int16_t_min: %d\n", *(int16_t *)GetVar("int16_t_min", nh));
    printf("int16_t_max: %d\n", *(int16_t *)GetVar("int16_t_max", nh));
    printf("uint16_t_max: %u\n", *(uint16_t *)GetVar("uint16_t_max", nh));
    printf("int32_t_min: %d\n", *(int32_t *)GetVar("int32_t_min", nh));
    printf("int32_t_max: %d\n", *(int32_t *)GetVar("int32_t_max", nh));
    printf("uint32_t_max: %u\n", *(uint32_t *)GetVar("uint32_t_max", nh));
    printf("int64_t_min: %lld\n", *(int64_t *)GetVar("int64_t_min", nh));
    printf("int64_t_max: %lld\n", *(int64_t *)GetVar("int64_t_max", nh));
    printf("uint64_t_max: %llu\n", *(uint64_t *)GetVar("uint64_t_max", nh));
    printf("signed_char: %d\n", *(signed char *)GetVar("signed_char", nh));
    printf("unsigned_char: %u\n", *(unsigned char *)GetVar("unsigned_char", nh));
    printf("signed_int: %d\n", *(signed int *)GetVar("signed_int", nh));
    printf("unsigned_int: %u\n", *(unsigned int *)GetVar("unsigned_int", nh));
    printf("signed_short: %d\n", *(signed short *)GetVar("signed_short", nh));
    printf("unsigned_short: %u\n", *(unsigned short *)GetVar("unsigned_short", nh));
    printf("signed_long: %ld\n", *(signed long *)GetVar("signed_long", nh));
    printf("unsigned_long: %lu\n", *(unsigned long *)GetVar("unsigned_long", nh));
    printf("signed_long_long: %lld\n", *(signed long long *)GetVar("signed_long_long", nh));
    printf("unsigned_long_long: %llu\n", *(unsigned long long *)GetVar("unsigned_long_long", nh));
    printf("character: %c\n", *(char *)GetVar("character", nh));
    printf("integer: %d\n", *(int *)GetVar("integer", nh));
    printf("short_value: %d\n", *(short *)GetVar("short_value", nh));
    printf("long_value: %ld\n", *(long *)GetVar("long_value", nh));
    printf("long_long_value: %lld\n", *(long long *)GetVar("long_long_value", nh));
    printf("float_min: %f\n", *(float *)GetVar("float_min", nh));
    printf("float_max: %f\n", *(float *)GetVar("float_max", nh));
    printf("double_min: %lf\n", *(double *)GetVar("double_min", nh));
    printf("double_max: %lf\n", *(double *)GetVar("double_max", nh));
}


void test_arr(NodeHandler* nh) {
    // Arrays for each data type
    int8_t int8_arr[] = { -128, 0, 127 };
    uint8_t uint8_arr[] = { 0, 127, 255 };
    int16_t int16_arr[] = { -32768, 0, 32767 };
    uint16_t uint16_arr[] = { 0, 32767, 65535 };
    int32_t int32_arr[] = { -2147483648, 0, 2147483647 };
    uint32_t uint32_arr[] = { 0, 2147483647, 4294967295 };
    int64_t int64_arr[] = { -9223372036854775807, 0, 9223372036854775807 };
    uint64_t uint64_arr[] = { 0, 9223372036854775807, (uint64_t)18446744073709551615ULL };
    signed char signed_char_arr[] = { -128, 0, 127 };
    unsigned char unsigned_char_arr[] = { 0, 127, 255 };
    signed int signed_int_arr[] = { -2147483648, 0, 2147483647 };
    unsigned int unsigned_int_arr[] = { 0, 2147483647, 4294967295 };
    signed short signed_short_arr[] = { -32768, 0, 32767 };
    unsigned short unsigned_short_arr[] = { 0, 32767, 65535 };
    signed long signed_long_arr[] = { -2147483648, 0, 2147483647 };
    unsigned long unsigned_long_arr[] = { 0, 2147483647, 4294967295 };
    signed long long signed_long_long_arr[] = { -9223372036854775807, 0, 9223372036854775807 };
    unsigned long long unsigned_long_long_arr[] = { 0, 9223372036854775807, (unsigned long long)18446744073709551615ULL };
    char char_arr[] = { 'A', 'B', 'C' };
    int int_arr[] = { -2147483648, 0, 2147483647 };
    float float_arr[] = { 3.14f, 2.71f, 1.41f };
    double double_arr[] = { 3.14159265359, 2.71828182846, 1.61803398875 };
    short short_arr[] = { -32768, 0, 32767 };
    long long_arr[] = { -2147483648, 0, 2147483647 };
    long long long_long_arr[] = { -9223372036854775807, 0, 9223372036854775807 };

   
    // Add arrays using AddArr function
    AddArr(int8_arr, "int8_arr", INT8_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(uint8_arr, "uint8_arr", UINT8_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(int16_arr, "int16_arr", INT16_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(uint16_arr, "uint16_arr", UINT16_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(int32_arr, "int32_arr", INT32_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(uint32_arr, "uint32_arr", UINT32_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(int64_arr, "int64_arr", INT64_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(uint64_arr, "uint64_arr", UINT64_T_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(signed_char_arr, "signed_char_arr", SIGNED_CHAR_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(unsigned_char_arr, "unsigned_char_arr", UNSIGNED_CHAR_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(signed_int_arr, "signed_int_arr", SIGNED_INT_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(unsigned_int_arr, "unsigned_int_arr", UNSIGNED_INT_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(signed_short_arr, "signed_short_arr", SIGNED_SHORT_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(unsigned_short_arr, "unsigned_short_arr", UNSIGNED_SHORT_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(signed_long_arr, "signed_long_arr", SIGNED_LONG_ARR, nh, 3);
    printf("Arr added.\n");   
    AddArr(unsigned_long_arr, "unsigned_long_arr", UNSIGNED_LONG_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(signed_long_long_arr, "signed_long_long_arr", SIGNED_LONG_LONG_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(unsigned_long_long_arr, "unsigned_long_long_arr", UNSIGNED_LONG_LONG_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(char_arr, "char_arr", CHAR_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(int_arr, "int_arr", INT_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(float_arr, "float_arr", FLOAT_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(double_arr, "double_arr", DOUBLE_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(short_arr, "short_arr", SHORT_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(long_arr, "long_arr", LONG_ARR, nh, 3);
    printf("Arr added.\n");
    AddArr(long_long_arr, "long_long_arr", LONG_LONG_ARR, nh, 3);
    printf("Arr added.\n");

    printf("Getting em.\n");


    // Print arrays using the corresponding print functions
    print_int8_arr((int8_t*)GetArr("int8_arr", nh), 3);
    print_uint8_arr((uint8_t*)GetArr("uint8_arr", nh), 3);
    print_int16_arr((int16_t*)GetArr("int16_arr", nh), 3);
    print_uint16_arr((uint16_t*)GetArr("uint16_arr", nh), 3);
    print_int32_arr((int32_t*)GetArr("int32_arr", nh), 3);
    print_uint32_arr((uint32_t*)GetArr("uint32_arr", nh), 3);
    print_int64_arr((int64_t*)GetArr("int64_arr", nh), 3);
    print_uint64_arr((uint64_t*)GetArr("uint64_arr", nh), 3);
    print_signed_char_arr((signed char*)GetArr("signed_char_arr", nh), 3);
    print_unsigned_char_arr((unsigned char*)GetArr("unsigned_char_arr", nh), 3);
    print_signed_int_arr((signed int*)GetArr("signed_int_arr", nh), 3);
    print_unsigned_int_arr((unsigned int*)GetArr("unsigned_int_arr", nh), 3);
    print_signed_short_arr((signed short*)GetArr("signed_short_arr", nh), 3);
    print_unsigned_short_arr((unsigned short*)GetArr("unsigned_short_arr", nh), 3);
    print_signed_long_arr((signed long*)GetArr("signed_long_arr", nh), 3);
    print_unsigned_long_arr((unsigned long*)GetArr("unsigned_long_arr", nh), 3);
    print_signed_long_long_arr((signed long long*)GetArr("signed_long_long_arr", nh), 3);
    print_unsigned_long_long_arr((unsigned long long*)GetArr("unsigned_long_long_arr", nh), 3);
    print_char_arr((char*)GetArr("char_arr", nh), 3);
    print_int_arr((int*)GetArr("int_arr", nh), 3);
    print_float_arr((float*)GetArr("float_arr", nh), 3);
    print_double_arr((double*)GetArr("double_arr", nh), 3);
    print_short_arr((short*)GetArr("short_arr", nh), 3);
    print_long_arr((long*)GetArr("long_arr", nh), 3);
    print_long_long_arr((long long*)GetArr("long_long_arr", nh), 3);
}

int main(void) { 
    NodeHandler *nh = InitDS();
    test(nh);
    printf("\n\n\n");
    test_arr(nh);
    KillDS(nh);
}
