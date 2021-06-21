#ifndef ADDRESSHELPER_H
#define ADDRESSHELPER_H

unsigned int get_tag(unsigned int address);

unsigned int get_offset(unsigned int address);

unsigned int find_set(int address);

unsigned int find_set_by_blocknum(unsigned int blocknum);

#endif //ADDRESSHELPER_H
