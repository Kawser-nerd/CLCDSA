import java.util.*;

public class Main {
    static int modP = 1000000007;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        int[] c = new int[m];

        int[][] cost = new int[n][n];
        int inf = 1 << 29;
        for(int i = 0; i < n; i++) Arrays.fill(cost[i], inf);
        for(int i = 0; i < n; i++) cost[i][i] = 0;
        for(int i = 0; i < m; i++) {
            a[i] = in.nextInt()-1;
            b[i] = in.nextInt()-1;
            c[i] = in.nextInt();
            cost[a[i]][b[i]] = c[i];
            cost[b[i]][a[i]] = c[i];
        }

        boolean used[] = new boolean[m];
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j) continue;
                    cost[i][j] = Math.min(cost[i][k] + cost[k][j], cost[i][j]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) if(c[i] > cost[a[i]][b[i]]) ans++;

        print(ans);
    }

    static void print(String s) {
        System.out.println(s);
    }

    static void print(int i) {
        System.out.println(i);
    }
}

class E {
    int l, r, w;
    E(int l, int r, int w) {
        this.l = l;
        this.r = r;
        this.w = w;
    }
}