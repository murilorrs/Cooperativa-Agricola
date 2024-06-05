#include <stdio.h>
#include <math.h>

float perimetro(float, float, float)

float area(float, float, float, float);

int main (){
    float a, b, c, ar;

    printf("Entre com os dados a b c do triangulo\n");
    scanf("%f %f %f", &a, &b, &c);

    perimetro = perimetro(a,b,c);

    printf("Perimetro: %f", perimetro);

    ar = area(perimetro(a,b,c), a, b , c);

    printf("Area: %f", ar );
    return 0;
}

void perimetro(float a, float b, float c){

    int  perimetro;
    
    perimetro = a + b + c;

    return perimetro;
}

float area(float perimetro, float a, float b, float c){
    int area;
    area = sqrt(perimetro*(perimetro - a)*(perimetro - b)*(perimetro - c))    

    return area;
}

