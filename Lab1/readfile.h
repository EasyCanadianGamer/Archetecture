#ifndef READFILE_H
#define READFILE_H

int open_file(char *filename);
int close_file(void);
int read_int(int *value);
int read_string(char *value);
int read_float(float *value);

#endif