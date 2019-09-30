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
        int c = sc.nextInt();
        int k = sc.nextInt();
        int[] ts = new int[n];
        for (int i = 0; i < n; i++) {
            ts[i] = sc.nextInt();
        }

        Arrays.sort(ts);

        int ans = 0;
        int departT = ts[0] + k;
        int count = 1;
        for (int i = 1; i < n - 1; i++) {
            if (ts[i] > departT) {
                ans++;
                count = 0;
                departT = ts[i] + k;
            }

            count++;
            if (count == c) {
                ans++;
                count = 0;
                departT = ts[i + 1] + k;
            }
        }

        if (ts[n - 1] > departT) {
            ans++;
            count = 0;
        }

        ans++;
        System.out.println(ans);
    }
}