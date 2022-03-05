#include <stdio.h>
#include <math.h>

double PI = 3.14;

double prompt_double(char prompt[]) {
    printf("%s", prompt);
    double userInput = 0;
    scanf("%lf", &userInput);
    return userInput;
}

int main() {
    // Prompt values, and convert them to SI unit
    double r = prompt_double("R (in kiloohms)   : ") * 1e3;
    double l = prompt_double("L (in milliHenry) : ") * 1e-3;
    double c = prompt_double("C (in microFarad) : ") * 1e-6;
    double f = prompt_double("f (in Hertz)      : ");
    
    double omega = 2*PI*f;
    double z = sqrt(pow(r,2) + pow(omega*l-1/(omega*c),2));
    
    printf("Impedance, Z = %.2lf ohms\n", z);
    
    return 0;
}
