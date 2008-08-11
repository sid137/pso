#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <time.h>

#define func(x) cos(x)*exp(sin(x))*sin(x)/1.5
#define UNFIT 1000
#define NUM_PARTICLES 10
#define MAX_ITERATIONS 100

static double function(double a)
{
     return func(a);
}


int max_iterations = MAX_ITERATIONS;
int num_particles = NUM_PARTICLES;
double domain_min = -4.5;
double domain_max = 4.5;

double gbest_fitness, gbest_position;

typedef struct {
     double position; //should be array n dimension
     double velocity; //should also be array n dimension
     double fitness;
     double best_fitness;
     double best_position;
} particle;

particle population[NUM_PARTICLES];

/* particle pouplation, population size, domain min, domain max */
void initialize_particle(particle *);
void initialize_particles(particle[], int);
void update_velocity(particle *);
void update_position(particle *);
void evaluate(particle *);   //send function pointer 4 eval function
void print_status(void);


double uniform(double, double);


void initialize_particles(particle population[], int num_particles)
{
     int i;
     particle *p;
     for (i = 0; i < num_particles; i++) {
          p = &population[i];
          initialize_particle(p);
     }
}

void initialize_particle(particle *p){
          p->position = uniform(domain_min, domain_max);
          p->velocity = uniform(-1, 1);
          p->fitness = UNFIT;
          p->best_fitness = p->fitness; 
          p->best_position = p->position;
}

int main()
{
     srand(time(NULL));

     int i, j;
     particle *p;

     initialize_particles(population, num_particles);


     /* Main Loop */
     for ( i = 0; i < max_iterations; i++) {
          for (j = 0; j < num_particles; j++) {
               p = &population[j];
               update_velocity(p);
               update_position(p);
               evaluate(p);
          }         
     }

     print_status();
     printf("Done..\n");

     return 0;
}



void update_velocity(particle  *p) {
     double phi1 = uniform(0,2);
     double phi2 = uniform(0,2);

     p->velocity = p->velocity + phi1*(p->best_position-p->position) + phi2*(gbest_position-p->position);
}

void update_position(particle  *p) {
     p->position = p->position + p->velocity;
     if ((p->position < domain_min) || (p->position > domain_max))
          initialize_particle(p);
}



void evaluate(particle  *p) {
     p->fitness = function(p->position);

     if (p->fitness < p->best_fitness) {
          p->best_fitness = p->fitness;
          p->best_position = p->position;
     }

     if (p->fitness < gbest_fitness) {
          gbest_fitness = p->fitness;
          gbest_position = p->position;
     }
}

double uniform(double a, double b){
     return rand()/(RAND_MAX+1.0)*(b-a)+a;
}



void print_status(){
     int i;
     particle *p;
     for (i = 0; i < num_particles; i++) {
          p = &population[i];
          printf("Particle %i is at position %4.4f, fitness %4.4f, velocity %4.4f, bestl %4.4f\n", i+1, p->position, p->fitness, p->velocity, p->best_position); 
     }
     printf("Global best fitness is %4.12f at position %4.4f\n", gbest_fitness, gbest_position);

}


