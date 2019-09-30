import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    int n, k;
    E[] g;

    void run() {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt(); k = sc.nextInt();
        g = new E[n];
        for (int i = 0; i < n; i++) g[i] = new E();

        int[][] es = new int[n - 1][2];

        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
            es[i][0] = a; es[i][1] = b;
            g[a].add(b);
            g[b].add(a);
        }

        int ans = 0;

        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                boolean[] visited = new boolean[n];
                ans = Math.max(ans, dfs(i, k / 2, visited));
            }
        } else {
            for (int i = 0; i < n - 1; i++) {
                boolean[] visited = new boolean[n];
                visited[es[i][0]] = visited[es[i][1]] = true;
                int tmp = dfs(es[i][0], k / 2, visited) + dfs(es[i][1], k / 2, visited);
                ans = Math.max(ans, tmp);
            }
        }

        System.out.println(n - ans);
    }

    int dfs(int c, int k, boolean[] visited) {
        visited[c] = true;
        if (k == 0) {
            return 1;
        }
        int sum = 1;
        for (int next: g[c]) if (!visited[next]) {
            sum += dfs(next, k - 1, visited);
        }
        return sum;
    }

    class E extends ArrayList<Integer>{}

    public static void main(String[] args) {
        new Main().run();
    }
}