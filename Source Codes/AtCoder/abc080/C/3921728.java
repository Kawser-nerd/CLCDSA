import java.util.*;
import java.lang.*;


public class Main {
    static int n;
    static int f[][];
    static int p[][];
    static long max = -1000000001;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        f = new int[n][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                f[i][j] = sc.nextInt();
            }
        }
        p = new int[n][11];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                p[i][j] = sc.nextInt();
            }
        }
        int dub[] = new int[n];
        dfs(0, dub);
        System.out.println(max);
    }
    static void dfs(int time, int[] dub) {
        if (time == 10) {
            boolean mu = false;
            for (int i = 0; i < n; i++) {
                if (dub[i] != 0) {
                    mu = true;
                    break;
                }
            }
            if (mu) {
                int benefit = 0;
                for (int i = 0; i < n; i++) {
                    benefit += p[i][dub[i]];
                }
                max = Math.max(max, benefit);
                return;
            } else {
                return;
            }
        }
        dfs(time + 1, dub);
        int d[];
        d = Arrays.copyOf(dub, n);
        for (int i = 0; i < n; i++) {
            if (f[i][time] == 1) {
                d[i]++;
            }
        }
        dfs(time + 1, d);
    }
}