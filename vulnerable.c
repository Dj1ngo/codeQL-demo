#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buffer_overflow() {
    char buffer[10];
    strcpy(buffer, "This is a very long string that will overflow the buffer!");
    printf("%s\n", buffer);
}

void format_string_vulnerability(char *user_input) {
    printf(user_input);
}

void use_after_free() {
    char *ptr = (char *)malloc(10);
    free(ptr);
    strcpy(ptr, "Use after free");
    printf("%s\n", ptr);
}

void null_pointer_dereference() {
    char *ptr = NULL;
    strcpy(ptr, "Null pointer dereference");
}

void command_injection() {
    char command[256];
    printf("Enter a command: ");
    scanf("%s", command);
    system(command);
}

int main(int argc, char *argv[]) {
    buffer_overflow();
    format_string_vulnerability(argv[1]);
    use_after_free();
    null_pointer_dereference();
    command_injection();
    return 0;
}
