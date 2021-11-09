/*  examples/miscellanea/print_format.c  */
/*

The following code will try to convert an `IniFormatNum` to an `IniFormat` and
print the C source code of the former. The generated `IniFormat` will be then
converted back to its `IniFormatNum`.

*/

#include <stdio.h>
#include <confini.h>


/*

General portable function for printing the C source code of an `IniFormat`
represented by an `IniFormatNum`

*/
void print_format_num (IniFormatNum fnum) {

  #define __MAX_1_BITS__ 1
  #define __MAX_2_BITS__ 3
  #define __MAX_3_BITS__ 7
  #define __MAX_4_BITS__ 15
  #define __MAX_5_BITS__ 31
  #define __MAX_6_BITS__ 63
  #define __MAX_7_BITS__ 127
  #define __MAX_8_BITS__ 255
  #define __PRINTF_ARGS__(NAME, OFFSET, SIZE, DEFVAL) \
    , (fnum >> OFFSET) & __MAX_##SIZE##_BITS__
  #define __PRINTF_STRING__(NAME, OFFSET, SIZE, DEFVAL) \
    "    ." #NAME " = %u,\n"
  #define PRINT_FORMAT_NUM() \
    printf("(IniFormat) {\n" INIFORMAT_TABLE_AS(__PRINTF_STRING__) "}" \
    INIFORMAT_TABLE_AS(__PRINTF_ARGS__))

  PRINT_FORMAT_NUM();

  #undef PRINT_FORMAT_NUM
  #undef __PRINTF_ARGS__
  #undef __PRINTF_STRING__
  #undef __MAX_8_BITS__
  #undef __MAX_7_BITS__
  #undef __MAX_6_BITS__
  #undef __MAX_5_BITS__
  #undef __MAX_4_BITS__
  #undef __MAX_3_BITS__
  #undef __MAX_2_BITS__
  #undef __MAX_1_BITS__

}

int main () {

  static const IniFormatNum MY_FORMAT_NUM = 786490;
  const IniFormat my_format = ini_ntof(MY_FORMAT_NUM);

  printf("IniFormat my_format = ini_ntof(%u);\n\n", MY_FORMAT_NUM);
  printf("ini_ntof(%u) ==> ", MY_FORMAT_NUM);
  print_format_num(MY_FORMAT_NUM);
  printf("\n\nini_fton(my_format) ==> (IniFormatNum) %u\n", ini_fton(my_format));

  return 0;

}

