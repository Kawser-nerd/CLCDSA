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
        int n =sc.nextInt();
        long all = 0;
        int[] as = new int[n + 2];
        as[0] = as[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            as[i] = sc.nextInt();
            all += Math.abs(as[i] - as[i - 1]);
        }
        all += Math.abs(as[n + 1] - as[n]);

        for (int i = 1; i <= n; i++) {
            int d = Math.abs(as[i] - as[i - 1]) + Math.abs(as[i + 1] - as[i]);
            int a = Math.abs(as[i + 1] -  as[i - 1]);
            System.out.println(all - d + a);
        }
    }
}