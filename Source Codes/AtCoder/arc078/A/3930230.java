import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        long sum = 0l;
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
            sum += as[i];
        }

        long ans = Long.MAX_VALUE;
        long x = 0;
        for (int i = 0; i < n - 1; i++) {
            x += as[i];
            ans = Math.min(ans, Math.abs(x - (sum - x)));
        }
        System.out.println(ans);
    }
}