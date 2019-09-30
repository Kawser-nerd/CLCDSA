/* 
 * File:   main.c
 * Author: 
 *
 * Created on April 30, 2017, 10:50 AM
 */

#include <stdio.h>
#include <stdlib.h>

struct core_info {
    double propability;
    unsigned char aided;
};

int compareProbabilities(const void* a, const void* b) {
    const double* da = (const double*) a;
    const double* db = (const double*) b;

    if (*da > *db)
        return 1;
    if (*da < *db)
        return -1;
    return 0;
}

void get_cores(unsigned* total, unsigned * required) {
    scanf("%d %d", total, required);
}

void get_tests(unsigned* tests) {
    scanf("%d", tests);
}

void get_trainings(double* trainings) {
    scanf("%lf", trainings);
}

void get_probabilities(double* probabilities, unsigned count) {
    unsigned p;

    for (p = 0; p < count; ++p) {
        scanf("%lf", probabilities + p);
    }

    qsort(probabilities, count, sizeof (double), compareProbabilities);
}

void give_aid_to_cores(double* cores, unsigned count, double training) {
    while (training > 0) {
        double needs = 0;
        unsigned c, ct;

        for (c = 1, ct = 1; c < count; ++c) {
            if (cores[c] > cores[c - 1]) {
                needs = cores[c] - cores[c - 1];
                break;
            }
            ++ct;
        }

        if (needs == 0)
            break;

        needs *= ct;
        if (needs > training) {
            needs = training;
        }
        training -= needs;
        needs /= ct;

        for (c = 0; c < ct; ++c) {
            cores[c] += needs;
        }

/*
        for (c = 0; c < count; ++c) {
            printf("%.4f ", cores[c]);
        }
        puts("");
*/
    }

    if (training > 0) {
        unsigned c;
        double needs = 1 - cores[0];
        
        needs *= count;
        if (needs > training)
            needs = training;
        needs /= count;
        
        for (c = 0; c < count; ++c) {
            cores[c] += needs;
        }

/*
        for (c = 0; c < count; ++c) {
            printf("%.4f ", cores[c]);
        }
        puts("");
*/
    }
}

double give_final_result(double* cores, unsigned count) {
    double result = 1;
    unsigned c;

    for (c = 0; c < count; ++c) {
        result *= cores[c];
    }

    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned tests, total_cores, required_cores;
    double trainings;
    double* cores;

    unsigned t;

    get_tests(&tests);

    for (t = 0; t < tests; ++t) {
        get_cores(&total_cores, &required_cores);
        get_trainings(&trainings);

        cores = malloc(sizeof (double) * total_cores);
        get_probabilities(cores, total_cores);

        give_aid_to_cores(cores, total_cores, trainings);

        printf("Case #%d: %f\n", t + 1, give_final_result(cores, total_cores));

        free(cores);
    }

    return (EXIT_SUCCESS);
}

