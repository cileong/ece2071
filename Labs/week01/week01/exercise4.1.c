#include <stdio.h>

int prompt_int(char prompt[]) {
    printf("%s", prompt);
    int user_input = 0;
    scanf("%d", &user_input);
    return user_input;
}

int main() {
    int input_value = prompt_int("Input the number of seconds: ");
    
    int hours = input_value / 3600;
    int minutes = (input_value % 3600) / 60;
    int seconds = input_value % 60;
    
    printf("%d seconds is equivalent to:\n", input_value);
    printf("%d hours, %d minutes, and %d seconds\n",
        hours, minutes, seconds);
    
    return 0;
}
