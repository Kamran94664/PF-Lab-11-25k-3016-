#include <stdio.h>

float meterToKm(float meters)
{
    const float M_TO_KM = 0.001;

    static int callCount = 0;
    callCount = callCount + 1;

    printf("Function called %d times.\n", callCount);

    return meters * M_TO_KM;
}

int main()
{
    float m;
    float result;

    printf("Enter meters: ");
    scanf("%f", &m);

    result = meterToKm(m);

    printf("Kilometers: %.3f\n", result);

    return 0;
}
