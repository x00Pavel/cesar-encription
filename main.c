#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1
#define OK 0
#define MAX 64

typedef unsigned int uint;

/*bool parse_string(char* string){
    // char* i = (char*) malloc(64 * sizeof(char));
    uint i;
    size_t len = strlen(string);
    printf("len: %ld\n", len);
    for (size_t j = 0; j < len; j++) {
        i = string[i];
        if (i == 32) {
            continue;
        } else if (i < 65) {
            printf("In first: %c : %d\n", i, i);
            return false;
        }
        else if (i > 90 && i < 97){
            printf("In second: %c : %d\n", i, i);
            return false;
        }
        else if (i > 122) {
            printf("In thread: %c : %d\n", i, i);
            return false;
        }
        printf("%c\n", i);
    }
    return true;
}*/

int insert_string(char *result){

    printf("Insert string do encrypt: ");
    fgets(result, MAX, stdin);
    
    // bool parse = parse_string(result);
    // if (!parse){
    //     printf("Parsing failed\n");
    //     return -1;
    // }
    return 1;
}

int insert_offset(){

    int result;
    printf("Insert offset: ");
    int rc = scanf("%d", &result);
    if (rc <= 0){
        return ERROR;
    }
    return result;
}

char* do_encryption(char* string, int offset){
    (void)string;
    (void)offset;
    size_t len = strlen(string) - 1; // Because of deafult terminated character in the end of string
    char* result = (char*)malloc(len * sizeof(char));

    // Do this best
    // for (size_t i = 0; i < len; i++){
    //     result[i] = (char)((int)string[i] + offset);
    // }
    for (size_t i = 0; i < len; i++) {
        int dec_val = (int)string[i];
        if (dec_val == 32){ // If there is other symbols? Do parsing?
            result[i] = string[i];
        }
        else{
            int new_dec_val = dec_val + offset;
            if (new_dec_val > 122){
                int left = offset - (122 - dec_val);
                result[i] = (char)(96 + left);
            } else if (new_dec_val > 90 && dec_val <= 90){
                int left = offset - (90 - dec_val);
                result[i] = (char)(96 + left);
                }
            else{
                result[i] = (char)(dec_val + offset);
            }
        }
    }

    return result;
}

int main(){

    char* string = (char*) malloc(MAX * sizeof(char));
    int rc = insert_string(string);
    if (rc != 1){
        free(string);
        printf("Wrong input!\n");
        return ERROR;
    }

    int offset = insert_offset();

    if (offset < 0){
        printf("Offset must be greater of equal then 0!");
        free(string);
        return ERROR;
    }

    char* output = do_encryption(string, offset); // Можно сделать без создания вспомогательного масссива

    printf("Output is: %s\n", output);
    free(output);
    free(string);
    return OK;
}
