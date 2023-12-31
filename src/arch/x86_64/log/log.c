#include <arch/x86_64/log/log.h>

void arch_log_init(void){
    io_write8(0x3f8 + 1, 0x00);
    io_write8(0x3f8 + 3, 0x80);
    io_write8(0x3f8 + 0, 0x03);
    io_write8(0x3f8 + 1, 0x00);
    io_write8(0x3f8 + 3, 0x03);
    io_write8(0x3f8 + 2, 0xC7);
    io_write8(0x3f8 + 4, 0x0b);
    io_write8(0x3f8 + 4, 0x0f);

    load_info.arch_log = 0;
}

void arch_log_put_char(char c){
    io_write8(0x3f8, c);
}

void arch_log_print(const char* str){
    while(*str){
        arch_log_put_char(*str);
        str++;
    }
}
