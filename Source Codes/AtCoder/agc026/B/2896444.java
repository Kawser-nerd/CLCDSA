import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int t = 0; t < T; t++) {
            long A = sc.nextLong();
            long B = sc.nextLong();
            long C = sc.nextLong();
            long D = sc.nextLong();

            if (B > A) {
                System.out.println("No");
                continue;
            }

            if (B > D) {
                System.out.println("No");
                continue;
            }

            if (C >= B) {
                System.out.println("Yes");
                continue;
            }

            long g = gcd(B, D);

            if (B - g + (A % g) > C) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }

        }
    }

    private static long gcd(long a, long b) {
        long c = a % b;
        if (c == 0) return b;
        return gcd(b, c);
    }
}