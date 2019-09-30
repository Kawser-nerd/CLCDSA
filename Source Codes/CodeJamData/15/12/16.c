
#include <stdio.h>
#include <sys/wait.h>
#include <stdint.h>

int index_of_min(uint64_t a[], int n){
    uint64_t min_elt = a[0];
    int min_idx = 0, i;
    for (i = 1; i < n; i++){
        if (a[i] < min_elt){
            min_elt = a[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int which_barber(int num_barbers, int num_customers, int speeds[])
{
    uint64_t times[num_barbers];
    int customer, barber_idx;

    for (barber_idx = 0; barber_idx < num_barbers; barber_idx++){
        times[barber_idx] = 0ULL;
    }

    for (customer = 0; customer < num_customers; customer++){
        barber_idx = index_of_min(times, num_barbers);
        times[barber_idx] += speeds[barber_idx];
    }
    return barber_idx;
}

int main()
{
    int num_cases;
    scanf("%d", &num_cases);

    int casenum;
    int Speeds[1000];
    int num_barbers, num_customers, barber_idx;

    char filename[100];

    int procs_active = 0, done = 0,_status;

    for (casenum = 0; casenum < num_cases; casenum++){
        scanf("%d %d", &num_barbers, &num_customers);

        for (barber_idx = 0; barber_idx < num_barbers; barber_idx++){
            scanf("%d", &Speeds[barber_idx]);
        }

        int pid = fork();
        if (pid == 0){
            int result = which_barber(num_barbers, num_customers, Speeds);

            sprintf(filename, "hair/%d.txt", casenum);
            FILE * file = fopen(filename, "w");
            fprintf(file, "%d", result);
            fclose(file);
            return 0;
        }

        procs_active++;
        if (procs_active >= 4){
            wait(&_status);
            procs_active--;
            done++;
            fprintf(stderr, " [done %d...]\n", done);
        }
    }

    while (procs_active >= 0){
        wait(&_status);
        procs_active--;
        done++;
        fprintf(stderr, " [done %d...]\n", done);
    }

    // now print all the results
    for (casenum = 0; casenum < num_cases; casenum++){
        sprintf(filename, "hair/%d.txt", casenum);
        FILE * file = fopen(filename, "r");
        int result;
        fscanf(file, "%d", &result);
        fclose(file);
        printf("Case #%d: %d\n", casenum + 1, result + 1);
    }

    return 0;
}

