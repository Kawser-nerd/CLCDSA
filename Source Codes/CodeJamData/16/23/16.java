import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = Integer.parseInt(s.nextLine());
        for (int t = 1; t <= T; t++) {
            int n = Integer.parseInt(s.nextLine());
            Map<String, Integer> leftMap = new HashMap<>(), rightMap = new HashMap<>();
            int count = 0;
            List<List<Integer>> e = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String[] pair = s.nextLine().split(" ");
                String left = pair[0], right = pair[1];
                if (!leftMap.containsKey(left)) {
                    leftMap.put(left, count++);
                    e.add(new ArrayList<>());
                }
                if (!rightMap.containsKey(right)) {
                    rightMap.put(right, count++);
                    e.add(new ArrayList<>());
                }
                int u = leftMap.get(left), v = rightMap.get(right);
                e.get(u).add(v);
                e.get(v).add(u);
            }
            int[] match = new int[count];
            for (int i = 0; i < count; i++) {
                match[i] = -1;
            }
            int ans = 0;
            boolean[] check = new boolean[count];
            Collection<Integer> us = leftMap.values();
            for (int u : us) {
                if (match[u] == -1) {
                    for (int i = 0; i < count; i++) {
                        check[i] = false;
                    }
                    check[u] = true;
                    if (dfs(u, match, check, e)) {
                        ans++;
                    }
                }
            }
            System.out.println(String.format("Case #%d: %d", t, n - (count - ans)));
        }
        s.close();
    }

    public static boolean dfs(int u, int[] match, boolean[] check, List<List<Integer>> e) {
        for (int v : e.get(u)) {
            if (!check[v]) {
                check[v] = true;
                if (match[v] == -1 || dfs(match[v], match, check, e)) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        return false;
    }
}