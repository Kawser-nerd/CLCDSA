import java.util.*;

public class Main {
    public void main(Scanner sc) {
        long n = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long d = sc.nextLong();

        long dur = a - b;
        for (int up = 0; up < n - 1; up++) {
            long max = d * up - c * (n - 1 - up);
            long min = c * up - d * (n - 1 - up);
            if (min <= dur && dur <= max) {
                System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}