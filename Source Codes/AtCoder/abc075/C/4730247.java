import java.util.Arrays;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    private static int n;
    private static boolean[] visited;
    private static boolean[][] graph;
    public static void main(String[] args) {
        n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = new int[m], b = new int[m];
        graph = new boolean[n][n];
        visited = new boolean[n];
        for (int i = 0; i < m; i++)
            graph[a[i] = scanner.nextInt() - 1][b[i] = scanner.nextInt() - 1] = graph[b[i]][a[i]] = true;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
            Arrays.fill(visited, false);
            dfs(0);
            if (IntStream.range(0, n).anyMatch(j -> !visited[j]))
                ans++;
            graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
        }
        System.out.println(ans);
    }

    private static void dfs(int v) {
        visited[v] = true;
        for (int v2 = 0; v2 < n; v2++)
            if (graph[v][v2] && !visited[v2])
                dfs(v2);
    }
}