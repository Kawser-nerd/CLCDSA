import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    int n, k, cnt;
    ArrayList<Integer>[] es;
    int[] parent;

    void run() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt(); k = sc.nextInt();
        es = new ArrayList[n];
        parent = new int[n];
        for (int i = 0; i < n; i++) es[i] = new ArrayList<>();
        cnt = sc.nextInt() != 1 ? 1 : 0;

        for (int i = 1; i < n; i++) {
            int next = sc.nextInt() - 1;
            es[next].add(i);
            parent[i] = next;
        }
        dfs(0);
        System.out.println(cnt);
    }

    int dfs(int p) {
        int max = 0;
        for (int next: es[p]) {
            max = Math.max(max, dfs(next));
        }
        max++;
        if (p == 0) return 0;
        debug(p, max);
        if (max == k && parent[p] != 0) {
            cnt++;
            return 0;
        } else {
            return max;
        }
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.