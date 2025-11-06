#include <math.h>
#include <stdio.h>

void printHelp(void){
    printf("\n\nHello!\n"
           "This command line calculator accumulates results from past operations, starting with 0\n"
           "To perfom an operation enter one of the following operators:\n");

    printf("\nBinary operators: \n"
           "+ = addition        \n"
           "- = subtraction     \n"
           "* = multiplication  \n"
           "/ = division        \n"
           "^ = power to\n");

    printf("\nUnary operators:  \n"
           "# = square root     \n"
           "%% = modulo         \n"
           "! = devide 1 with sum\n"
           "q = quit          \n\n");
}

void scan_data(char *operatorP, double *operandP){
    
    int inputCheckOperator = 0, inputCheckOperand = 0;
    
    do{
        printf("Please enter operator> ");
        scanf(" %c", operatorP);    // Space before %c avoid scanf reading newline from enter

        // If unary operator return
        if(*operatorP == '#' || *operatorP == '%' || *operatorP == '!' || *operatorP == 'q'){
            
            inputCheckOperator = 1;
            *operandP = 0;
            return;

        }
        // If binary continue
        else if(*operatorP == '+' || *operatorP == '-' || *operatorP == '*' || *operatorP == '/' || *operatorP == '^'){
            
            inputCheckOperator = 1;
            continue;

        }
        // if 'h' print help
        else if(*operatorP == 'h'){
            printHelp();
        }

        else{
            printf("Please enter valid operator(write h for help)\n\n");
        }
    } while(inputCheckOperator == 0);

        printf("Please enter operand> ");
        inputCheckOperand = scanf("%lf", operandP);


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
        printf("Result so far is %lf\n\n", akkumulator);
        }
    
    }
    while(operator != 'q');

    return akkumulator;

}
