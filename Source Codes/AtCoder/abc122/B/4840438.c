#include <stdio.h>
#include <stdint.h>
#include <string.h>

int8_t main(void) {
    uint8_t buffer[11], max_acgt_len = 0, cur_acgt_len = 0;
    if (fgets(buffer, 11, stdin) != NULL) {
        for (uint8_t i = 0; i < strlen(buffer); i++) {
            if ((strchr("ACGT", buffer[i])) != NULL) {
                cur_acgt_len += 1;
                if (cur_acgt_len > max_acgt_len) {
                    max_acgt_len = cur_acgt_len;
                }
            } else {
                cur_acgt_len = 0;
            }
        }
    }
    printf("%d",max_acgt_len);
    return 0;
}