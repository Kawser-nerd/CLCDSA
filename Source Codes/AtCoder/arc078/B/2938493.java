import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            Map<Integer, List<Integer>> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                map.put(i, new ArrayList<>());
            }
            for (int i = 0; i < n - 1; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                map.get(a).add(b);
                map.get(b).add(a);
            }
            System.out.println(check(map) ? "Fennec" : "Snuke");
        }
    }

    static int dist;
    static int idxA, idxB;

    private static boolean check(Map<Integer, List<Integer>> map) {
        int n = map.size();
        dist = -1;
        idxA = -1;
        idxB = -1;

        boolean[] used = new boolean[n];
        dfs(map, 0, 0, used);

        Arrays.fill(used, false);
        used[idxB] = true;
        int cntA = dfs2(map, idxA, used);
        int cntB = n - cntA;

        return cntA > cntB;
    }

    private static int dfs2(Map<Integer, List<Integer>> map, int curIdx, boolean[] used) {
        int res = 1;
        used[curIdx] = true;
        for (int toIdx : map.get(curIdx)) {
            if ( used[toIdx] ) {
                continue;
            }
            res += dfs2(map, toIdx, used);
        }
        return res;
    }

    private static boolean dfs(Map<Integer, List<Integer>> map, int curIdx, int curDist, boolean[] used) {
        int n = map.size();
        if ( curIdx == n - 1 ) {
            dist = curDist;
            return true;
        }
        used[curIdx] = true;

        for (int toIdx : map.get(curIdx)) {
            if ( used[toIdx] ) {
                continue;
            }
            boolean res = dfs(map, toIdx, curDist + 1, used);
            if ( res ) {
                if ( curDist == dist / 2 ) {
                    idxA = curIdx;
                    idxB = toIdx;
                }
                return true;
            }
        }
        return false;
    }
}