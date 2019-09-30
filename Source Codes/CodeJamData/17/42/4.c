#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REPEAT(token, num) for (token = 0; token < num; token++)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
static inline long long min(long long length1, long long length2) { return (length1 < length2) ? length1 : length2; }
static inline long long max(long long length1, long long length2) { return (length1 > length2) ? length1 : length2; }

//#define DEBUG
#ifdef DEBUG
#define PRINTF printf
#else
#define PRINTF(...) 1
#endif

typedef long test_cases;
typedef long seat;
typedef long num_seats;
typedef long customer;
typedef long num_customers;
typedef long num_tickets;
typedef long num_rides;
typedef long num_changes;

num_seats coasterLength;
num_customers numCustomers;
num_tickets numTickets, customerDistribution[2], seatDistribution[2][1000];
num_rides answer1;
num_changes answer2;

int main() {
    test_cases numTestCases, l;
    seat storeSeat, i, j;
    num_seats storeNum;
    customer storeCustomer;
    num_tickets m;
    scanf("%li", &numTestCases);

    REPEAT(l, numTestCases) {
        scanf("%li %li %li", &coasterLength, &numCustomers, &numTickets);
        memset(customerDistribution, 0, sizeof(customerDistribution));
        memset(seatDistribution, 0, sizeof(seatDistribution));
        REPEAT(m, numTickets) {
            scanf("%li %li", &storeSeat, &storeCustomer);
            //if (l == 29) printf("T %li %li\n", storeSeat, storeCustomer);
            customerDistribution[storeCustomer-1]++;
            seatDistribution[storeCustomer-1][storeSeat-1]++;
        }
        //if (l == 31) REPEAT(i, coasterLength) printf("D %li %li\n", seatDistribution[0][i], seatDistribution[1][i]);
        answer1 = 0;
        REPEAT(i, coasterLength) if (seatDistribution[0][i] > 0) {
            REPEAT(j, coasterLength) if ((j != i) && (seatDistribution[1][j] > 0) && (seatDistribution[0][j] > 0)) {
                storeNum = min(seatDistribution[0][i], seatDistribution[1][j]);
                seatDistribution[0][i] -= storeNum;
                seatDistribution[1][j] -= storeNum;
                customerDistribution[0] -= storeNum;
                customerDistribution[1] -= storeNum;
                answer1 += storeNum;
            }
            REPEAT(j, coasterLength) if ((j != i) && (seatDistribution[1][j] > 0)) {
                storeNum = min(seatDistribution[0][i], seatDistribution[1][j]);
                seatDistribution[0][i] -= storeNum;
                seatDistribution[1][j] -= storeNum;
                customerDistribution[0] -= storeNum;
                customerDistribution[1] -= storeNum;
                answer1 += storeNum;
            }
        }
        answer2 = 0;
        if ((customerDistribution[0] > 0) && (customerDistribution[1] > 0)) {
            if (seatDistribution[0][0] > 0) answer1 += customerDistribution[0]+customerDistribution[1];
            else {
                answer2 = min(customerDistribution[0], customerDistribution[1]);
                answer1 += max(customerDistribution[0], customerDistribution[1]);
            }
        }
        else answer1 += max(customerDistribution[0], customerDistribution[1]);
        printf("Case #%li: %li %li\n", l+1, answer1, answer2);
    }
    
    exit(0);
}