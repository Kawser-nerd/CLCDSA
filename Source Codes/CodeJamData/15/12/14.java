import java.util.Scanner;

public class B {
    static int B;
    static long N;
    static long[] M;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            B = sc.nextInt();
            N = sc.nextLong();
            M = new long[B + 1];
            for (int i = 1; i <= B; i++) {
                M[i] = sc.nextLong();
            }
            System.out.println("Case #" + caseNum + ": " + solve());
        }
    }

    static long solve() {
        if (N <= B) {
            return N;
        }
        long time = getHaircutTime();
        long customers = numCustomers(time);
        for (int i = B; i > 0; i--) {
            if (time % M[i] == 0) {
                if (customers == N) {
                    return i;
                }
                customers--;
            }
        }
        throw new IllegalStateException();
    }

    static long getHaircutTime() {
        long min = 0;
        long max = 100_000_000_000_000L;
        while (min < max) {
            long mid = (min + max) / 2;
            long customers = numCustomers(mid);
            if (customers < N) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        return min;
    }

    private static long numCustomers(long time) {
        long customers = 0;
        for (int i = 1; i <= B; i++) {
            customers += 1 + (time / M[i]);
        }
        return customers;
    }
}
