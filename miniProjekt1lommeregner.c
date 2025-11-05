//
//  This program is a command line calculator
//

#include <stdio.h>
#include <math.h>

void scan_data(char *operatorP, double *operandP);

void do_next_op(char operator, double operand, double *akkumulatorP);

double run_calculator();

int main(void){

    printf("\nCalculator v3.13\n\n");

    printf("The final result is %lf\n", run_calculator());

    return 0;

}

void scan_data(char *operatorP, double *operandP){
    
    int inputCheck = 0;
    
    do{
        printf("Please enter operator> ");
        scanf(" %c", operatorP);    // Space before %c avoid scanf reading newline from enter

        // If unary operator return
        if(*operatorP == '#' || *operatorP == '%' || *operatorP == '!' || *operatorP == 'q'){
            
            inputCheck = 1;
            *operandP = 0;
            return;

        }
        // If binary continue
        else if(*operatorP == '+' || *operatorP == '-' || *operatorP == '*' || *operatorP == '/' || *operatorP == '^'){
            
            inputCheck = 1;
            continue;

        }
        else{
            printf("Please enter valid operator.\n");
        }
    } while(inputCheck == 0);

    // lav input kontrol?
    printf("Please enter operand> ");
    scanf("%lf", operandP);

}

void do_next_op(char operator, double operand, double *akkumulatorP){
    switch(operator){
        case '+':
            *akkumulatorP += operand;
            break;
        case '-':
            *akkumulatorP -= operand;
            break;
        case '*':
            *akkumulatorP *= operand;
            break;
        case '/':
            if(operand == 0){
                break;
            }
            *akkumulatorP /= operand;
            break;
        case '^':
            *akkumulatorP = pow(*akkumulatorP, operand);
            break;
        case '#':
            if(*akkumulatorP < 0){
                break;
            }
            *akkumulatorP = sqrt(*akkumulatorP);
            break;
        case '%':
            *akkumulatorP *= -1;
            break;
        case '!':
            if(*akkumulatorP == 0){
                break;
            }
            *akkumulatorP = 1 / *akkumulatorP;
            break;
        case 'q':
            return;
    }
}

double run_calculator(){

    char operator;
    double operand;
    double akkumulator = 0;

    do{
        scan_data(&operator, &operand);
        
        do_next_op(operator, operand, &akkumulator);

        if(operator != 'q'){
        printf("Result so far is %lf\n", akkumulator);
        }
    
    }
    while(operator != 'q');

    return akkumulator;

}