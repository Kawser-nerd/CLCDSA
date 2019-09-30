#include <stdio.h>
#include <stdlib.h>

typedef struct event {
    long long pos; long long people;
} event;

int comp(const void *a, const void *b) {
    event *c = (event*)a, *d = (event*)b;
    if (c->pos < d->pos) return -1;
    if (c->pos == d->pos) return 0;
    return 1;
}

event start[1010], end[1010];
long long stack_pos[1010], stack_amount[1010], s_top;

int main() {
    FILE *input = fopen("a.in", "r");
    FILE *output = fopen("a.out", "w");

    int num_tests;
    long long num_stops, num_trips;
    long long read_start, read_end, people, dist;
    long long should_total, real_total;
    long long ans;
    int i, j, k;
    long long curr_start, curr_end;

    fscanf(input, "%d ", &num_tests);
    for (i = 0; i < num_tests; i++) {
        should_total = real_total = 0;
        s_top = 0;
        curr_start = curr_end = 0;
        fscanf(input, "%lld %lld ", &num_stops, &num_trips);
        //if (i == 7) printf("%lld %lld\n", num_stops, num_trips);
        for (j = 0; j < num_trips; j++) {
            fscanf(input, "%lld %lld %lld ", &read_start, &read_end, &people);
            //if (i == 7) printf("%lld %lld %lld\n", read_start, read_end, people);
            start[j].pos = read_start; end[j].pos = read_end; start[j].people = end[j].people = people;
            dist = end[j].pos - start[j].pos;
            should_total += people*((dist == 0 ? 0 : num_stops*dist - (dist*(dist-1))/2) % 1000002013LL);
            should_total %= 1000002013LL;
        }
        qsort(start, j, sizeof(event), comp);
        qsort(end, j, sizeof(event), comp);
        while (curr_start < num_trips || curr_end < num_trips) {
            //printf("%lld %lld %lld %lld\n", end[curr_end], end_people[curr_end], start[curr_start], s_people[curr_start]);
            if (curr_start == num_trips || end[curr_end].pos < start[curr_start].pos) {
                while (end[curr_end].people) {
                    if (end[curr_end].people >= stack_amount[s_top-1]) {
                        end[curr_end].people -= stack_amount[s_top-1];
                        dist = end[curr_end].pos - stack_pos[s_top-1];
                        real_total += stack_amount[s_top-1] * ((dist == 0 ? 0 : num_stops*dist - (dist*(dist-1))/2) % 1000002013LL);
                        real_total %= 1000002013LL;
                        s_top--;
                    }
                    else {
                        stack_amount[s_top-1] -= end[curr_end].people;
                        dist = end[curr_end].pos - stack_pos[s_top-1];
                        //printf("TEST %lld %lld\n", dist, end[curr_end].people);
                        real_total += end[curr_end].people * ((dist == 0 ? 0 : num_stops*dist - (dist*(dist-1))/2) % 1000002013LL);
                        real_total %= 1000002013LL;
                        end[curr_end].people = 0;
                    }
                }
                //printf("%lld %lld\n", dist, real_total);
                curr_end++;
            }
            else {
                stack_pos[s_top] = start[curr_start].pos; 
                stack_amount[s_top++] = start[curr_start++].people;
            }
        }
        ans = should_total - real_total;
        if (ans < 0) ans += 1000002013LL;
        else ans %= 1000002013LL;
        fprintf(output, "Case #%d: %lld\n", i+1, ans);
    }

    return 0;
}