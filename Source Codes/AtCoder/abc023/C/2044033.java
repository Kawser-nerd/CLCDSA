import java.util.Scanner;

public class Main {
    static int r, c, k, n;
    static int[] rc, cc;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        k = sc.nextInt();
        n = sc.nextInt();
        rc = new int[n];
        cc = new int[n];
        for (int i = 0; i < n; i++) {
            rc[i] = sc.nextInt() - 1;
            cc[i] = sc.nextInt() - 1;
        }

        long ans = solve();
        System.out.println(ans);
    }

    static long solve() {
        int[] candyInR = new int[r + 1];
        int[] candyInC = new int[c + 1];
        for (int i = 0; i < n; i++) {
            candyInR[rc[i]]++;
            candyInC[cc[i]]++;
        }
        int[] countR = new int[n + 1];
        int[] countC = new int[n + 1];
        for (int i = 0; i < r; i++)
            countR[candyInR[i]]++;
        for (int i = 0; i < c; i++)
            countC[candyInC[i]]++;
        long ans = 0;
        for (int i = 0; i <= k; i++)
            ans += countR[i] * countC[k - i];
        for (int i = 0; i < n; i++) {
            int sum = candyInR[rc[i]] + candyInC[cc[i]];
            if (sum == k) ans--;
            if (sum == k + 1) ans++;
        }

        return ans;
    }
}