#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define func(x) cos(x)*exp(sin(x))*sin(x)/1.5

static uint16_t function(int a)
{
     return func(a);
}



void initialize_particles(void);
void update_velocity(void);
void update_position(void);
void evaluate(void);


uint8_t iterations = 100;


int main()
{


     printf("Done..\n");
     printf("Func(5) is: %6.2f", function(5)) 

     return 0;
}
