import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static List<Set<Integer>> edge;
    private static boolean[] checked;

    private static boolean dfs(int i) {
        if(checked[i]) return false;

        checked[i] = true;
        Set<Integer> set = edge.get(i);
        for(int j : set) {
            edge.get(j).remove(i);
            if(!dfs(j)) return false;
        }
        set.clear();
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        edge = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            edge.add(new HashSet<>());
        }
        for(int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            edge.get(u).add(v);
            edge.get(v).add(u);
        }

        checked = new boolean[n];
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(dfs(i)) res++;
        }

        System.out.println(res);

        sc.close();
    }
}