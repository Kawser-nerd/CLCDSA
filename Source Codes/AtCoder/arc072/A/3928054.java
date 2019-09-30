import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        long sumOfP = sc.nextLong();
        long countP = 0;
        long sumOfM = sumOfP;
        long countM = 0;

        if (sumOfP <= 0) {
            countP = -sumOfP + 1;
            sumOfP = 1;
        }

        if (sumOfM >= 0) {
            countM = sumOfM + 1;
            sumOfM = -1;
        }

        for (int i = 1; i < n; i++) {
            long a = sc.nextLong();

            if (sumOfP > 0) {
                if (sumOfP + a >= 0) {
                    countP += sumOfP + a + 1;
                    sumOfP = -1;
                } else {
                    sumOfP += a;
                }
            } else {
                if (sumOfP + a <= 0) {
                    countP += -(sumOfP + a) + 1;
                    sumOfP = 1;
                } else {
                    sumOfP += a;
                }
            }

            if (sumOfM > 0) {
                if (sumOfM + a >= 0) {
                    countM += sumOfM + a + 1;
                    sumOfM = -1;
                } else {
                    sumOfM += a;
                }
            } else {
                if (sumOfM + a <= 0) {
                    countM += -(sumOfM + a) + 1;
                    sumOfM = 1;
                } else {
                    sumOfM += a;
                }
            }
        }

        System.out.println(Math.min(countP, countM));
    }
}