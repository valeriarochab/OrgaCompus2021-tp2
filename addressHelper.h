#ifndef ADDRESSHELPER_H
#define ADDRESSHELPER_H

unsigned int get_tag(unsigned int address);

unsigned int get_offset(unsigned int address);

unsigned int find_set(unsigned int address);

unsigned int find_mba(unsigned int address);

unsigned int find_set_by_blocknum(int blocknum);

unsigned int get_tag_by_blocknum(int blocknum);

#endif //ADDRESSHELPER_H
