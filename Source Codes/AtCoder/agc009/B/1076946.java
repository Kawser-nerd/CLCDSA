import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by zzt on 17-1-22.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        ArrayList<Integer>[] graph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 1; i < N; i++) {
            int a = scanner.nextInt() - 1;
            graph[a].add(i);
        }
        System.out.println(dfs(0, graph) - 1);
    }
    private static int dfs(int v, ArrayList<Integer>[] graph) {
        if (graph[v].isEmpty()) {
            return 1;
        }
        int[] tmp = new int[graph[v].size()];
        for (int i = 0; i < tmp.length; i++) {
            int u = graph[v].get(i);
            tmp[i] = dfs(u, graph);
        }

        Arrays.sort(tmp);
        int max = 0;
        for (int t :
                tmp) {
            if (t <= max)
                max++;
            else max = t;
        }
        max++;
        return max;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.