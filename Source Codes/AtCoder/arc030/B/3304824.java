import java.util.*;

public class Main {
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt() - 1;

        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }

        ArrayList<Integer>[] table = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            table[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;

            table[a].add(b);
            table[b].add(a);
        }

        dfs(x, -1, h, table);

        System.out.println(ret);
    }

    public static boolean dfs(int now, int parent, int[] h, ArrayList<Integer>[] table) {
        boolean exist = h[now] == 1;

        for (int next : table[now]) {
            if (next == parent) continue;
            boolean child = dfs(next, now, h, table);
            if (child) ret += 2;
            exist |= child;
        }

        return exist;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.