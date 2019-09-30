import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        sc.nextLine();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            String[] line = sc.nextLine().split("/");
            long p = Long.parseLong(line[0]);
            long q = Long.parseLong(line[1]);

            long gcd = gcd(p, q);
            p /= gcd;
            q /= gcd;
            System.out.print("Case #" + caseNum + ": ");
            if (!isPowerOfTwo(q)) {
                System.out.println("impossible");
                continue;
            }

            boolean possible = false;
            long pow = 2;
            for (int gens = 1; gens <= 40; gens++) {
                if (pow * p >= q) {
                    System.out.println(gens);
                    possible = true;
                    break;
                }
                pow *= 2;
            }
            if (!possible) {
                System.out.println("impossible");
            }
        }
    }

    private static boolean isPowerOfTwo(long q) {
        if (q % 2 == 1) {
            return (q == 1);
        }
        return isPowerOfTwo(q / 2);
    }

    private static long gcd(long a, long b) {
        if (a == 0 || b == 0) {
            return a + b;
        }
        return gcd(b, a % b);
    }
}
