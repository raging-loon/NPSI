/*
 * Copyright 2021-2022 Conner Macolley
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

#ifndef __MAIN_VIGIL_H
#define __MAIN_VIGIL_H

#ifdef USELIBPCAP
struct lpcap_args{
  pcap_t * ex;
  char * iface_name;
  char * buffer;
};
void lp_thread(struct lpcap_args * );
void lp_thread_start(void * );
#endif

int main(int, char **);

void sigint_processor(int);
void print_help_and_exit();
void print_cpu_info();
void print_logo();
void arg_parser(int , const char **);




#endif /* __MAIN_VIGIL_H */