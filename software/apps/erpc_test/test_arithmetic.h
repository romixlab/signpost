/*
 * Generated by erpcgen 1.3.0 on Tue Nov 22 18:09:25 2016.
 *
 * AUTOGENERATED - DO NOT EDIT
 */

#if !defined(_test_arithmetic_h_)
#define _test_arithmetic_h_

#include <stdint.h>
#include <stdbool.h>

/*! @brief Arithmetic identifiers */
enum _Arithmetic_ids
{
    kArithmetic_service_id = 1,
    kArithmetic_add_id = 1,
    kArithmetic_sub_id = 2,
};

#if defined(__cplusplus)
extern "C" {
#endif

//! @name Arithmetic
//@{
float add(float a, float b);

float sub(float a, float b);
//@}

#if defined(__cplusplus)
}
#endif

#endif // _test_arithmetic_h_
