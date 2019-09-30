import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long c = sc.nextLong();
            long d = sc.nextLong();

            if (a < b) {
                System.out.println("No");
            } else if (d < b) {
                System.out.println("No");
            } else if (b <= c) {
                System.out.println("Yes");
            } else {
                long g = gcd(b, d);
                long max = b - g + (a % g);
                System.out.println(max <= c ? "Yes" : "No");
            }
        }
    }

    private long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}