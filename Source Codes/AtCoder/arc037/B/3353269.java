import java.util.*;

public class Main {
    static int N;
    static ArrayList<Integer>[] table;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        table = new ArrayList[N];
        visited = new boolean[N];

        for (int i = 0; i < N; i++) {
            table[i] = new ArrayList<>();
        }

        int ret = 0;

        int M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            table[a].add(b);
            table[b].add(a);
        }

        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (dfs(i, -1)) ret++;
        }

        System.out.println(ret);
    }

    static boolean dfs(int now, int parent) {
        if (now < 0 || now >= N) return true;
        if (visited[now]) return false;

        visited[now] = true;

        boolean ret = true;

        for (int next : table[now]) {
            if (next == parent) continue;
            ret &= dfs(next, now);
        }

        return ret;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.