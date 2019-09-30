import java.util.*;

public class Main {


    public static void main(String[] args) {
        new Main().execute();
    }


    public void execute() {
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int M = sc.nextInt();

        boolean[][] graph = new boolean[N + 1][N + 1];
        int[] visited = new int[N + 1];
        boolean[] tree = new boolean[N + 1];

        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u][v] = true;
            graph[v][u] = true;
        }

        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0) {
                tree[i] = dfs(i, i, 0, graph, visited);
            }
        }

        int cnt = 0;
        for (boolean b : tree) {
            if (b) {
                cnt++;
            }
        }

        System.out.println(cnt);
        sc.close();
    }

    private boolean dfs(int node, int root, int from, boolean[][] graph, int[] visited) {
        boolean flag = true;
        if (visited[node] != 0) {
            flag = false;
            return flag;
        }
        visited[node] = root;
        for (int i = 1; i < graph[node].length; i++) {
            if (i != from && graph[node][i]) {
                flag = dfs(i, root, node, graph, visited) && flag;
            }
        }
        return flag;
    }

}