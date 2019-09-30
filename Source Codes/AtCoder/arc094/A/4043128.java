import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int max = Math.max(a, Math.max(b, c));

        int ans = 0;
        int r = 0;
        if (a < max) {
            int d = max - a;
            ans += d / 2;
            r += d % 2;
        }

        if (b < max) {
            int d = max - b;
            ans += d / 2;
            r += d % 2;
        }

        if (c < max) {
            int d = max - c;
            ans += d / 2;
            r += d % 2;
        }

        if (r == 0) {
            System.out.println(ans);
        } else if (r == 1) {
            System.out.println(ans + 2);
        } else {
            System.out.println(ans + 1);
        }
    }
}