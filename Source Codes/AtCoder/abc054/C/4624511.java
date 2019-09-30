import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    static int ans = 0;

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();

        boolean[] visited = new boolean[N];
        boolean[][] bridges = new boolean[N][N];

        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            bridges[from][to] = bridges[to][from] = true;
        }

        visited[0] = true;
        dfs(N, 0, bridges, visited);
        System.out.println(ans);
    }

    private static void dfs(int N, int from, boolean[][] bridges, boolean[] visited) {
        boolean allVisit = true;
        for (int i = 0; i < N; i++) {
            allVisit &= visited[i];
        }
        if (allVisit) {
            ans++;
            return;
        }

        for (int i = 0; i < N; i++) {
            if (bridges[from][i] && !visited[i]) {
                visited[i] = true;
                dfs(N, i, bridges, visited);
                visited[i] = false;
            }
        }
    }
}