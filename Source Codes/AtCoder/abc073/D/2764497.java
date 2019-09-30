import java.util.*;

public class Main {
    static int modP = 1000000007;
    static long inf  = 1 << 61;

    static int n,m,r;
    static int[] R;
    static long[][] dist;
    static long ans = inf;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        r = in.nextInt();
        R = new int[r];
        for(int i = 0; i < r; i++) R[i] = in.nextInt()-1;

        visited = new boolean[r];
        Arrays.fill(visited, false);

        dist = new long[n][n];
        for(int i = 0; i < n; i++) {
            Arrays.fill(dist[i], inf);
            dist[i][i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            int c = in.nextInt();
            dist[a][b] = c;
            dist[b][a] = c;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = Math.min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }

        dfs(1, -1, 0);
        print(ans);
    }

    static void dfs(int cnt, int last, long d) {
        if(cnt == r+1) {
            ans = Math.min(ans, d);
            return;
        }

        for(int i = 0; i < r; i++) {
            if(!visited[i]) {
                visited[i] = true;
                if(last == -1) dfs(cnt+1, i, 0);
                else           dfs(cnt+1, i, d + dist[R[last]][R[i]]);
                visited[i] = false;
            }
        }
    }

    static void print(String s) {
        System.out.println(s);
    }

    static void print(int i) {
        System.out.println(i);
    }

    static void print(long i) {
        System.out.println(i);
    }
}

class P {
    int x, y;
    P(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class E {
    int from, to;
    long w;
    E(int from, int to, long w) {
        this.from = from;
        this.to = to;
        this.w = w;
    }
}