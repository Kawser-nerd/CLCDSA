import java.util.*;

public class Main {
    public void main(Scanner sc) {
        long n = sc.nextLong();
        long x = sc.nextLong();

        long ans = n;
        long a = n - x;
        long b = x;
        while (b != 0) {
            long r = a / b;
            long q = a % b;

            ans += 2 * b * r;
            if (q == 0) {
                ans -= b;
            }
            a = b;
            b = q;
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}