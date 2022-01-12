/*
 * Copyright 2021 Conner Macolley
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>

/* x = src
   y = dest
   x and y are interchangeable
   z = target
*/
#define IS_PORT_DEST_SRC(X,Y,Z)(X == Z || Y == Z)
#define IS_PRINTABLE_ASCII(X)(X > 32 || X < 127)


unsigned char * mac_ntoa(uint8_t * );
unsigned char * uc_mac_ntoa(unsigned char *);
unsigned char * ipv4_ntoa( uint32_t *);
unsigned char * u8_ipv4_ntoa(uint8_t * );
unsigned char * inet6_ntoa(uint8_t * );
char * get_formated_time();
int strloc(const char *  haystack,const char needle);


void fail(const char * , const char *);

#endif /* UTILS_H */