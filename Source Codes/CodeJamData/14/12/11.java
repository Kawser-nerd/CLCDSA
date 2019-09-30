import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class FBT {

    // private static String file = "data/r1bsample.txt";

    // private static String file = "data/r1b-B-small-attempt0.in";
    private static String file = "data/r1b-B-large.in";

    public static void main(String[] args) throws Exception {
        FileInputStream is = new FileInputStream(new File(file));
        Scanner scanner = new Scanner(is);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int n = scanner.nextInt();
            List<List<Integer>> adj = new ArrayList<List<Integer>>();
            for (int i = 0; i < n; i++) {
                adj.add(new ArrayList<Integer>());
            }
            for (int i = 0; i < n - 1; i++) {
                int x = scanner.nextInt() - 1;
                int y = scanner.nextInt() - 1;
                adj.get(x).add(y);
                adj.get(y).add(x);
            }

            Solver solver = new Solver(adj);
            int ans = Integer.MAX_VALUE;
            for (int p = 0; p < n; p++) {
                int val = solver.solve(-1, p);
                ans = Math.min(ans, val);
            }
            out(t, ans);
        }
    }

    static void out(int t, Object ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
    }

    static class Solver {
        List<List<Integer>> adj;
        HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> depth = new HashMap<Integer, Integer>();

        Solver(List<List<Integer>> adj) {
            this.adj = adj;
        }

        int solve(int p, int current) {
            // System.out.println("#solve(" + p + "," + current + ")");
            int id = getId(p, current);
            if (p >= 0 && memo.containsKey(id)) {
                return memo.get(id);
            }
            List<Integer> adjList = adj.get(current);
            int n = adjList.size();
            if (n == 0) {
                throw new RuntimeException();
            }
            if ((n == 2 && p >= 0) || (n == 1 && p < 0)) {
                // should cut the nodes under current
                int ans = getDepth(p, current) - 1;
                // System.out.println("ans(" + p + "," + current + ")=" + ans);
                memo.put(id, ans);
                return ans;
            }
            if (n == 1) {
                // System.out.println("ans(" + p + "," + current + ")=nochild");
                return 0;
            }
            int ans = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                int a = adjList.get(i);
                if (a == p) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    int b = adjList.get(j);
                    if (b == p) {
                        continue;
                    }
                    // try a & b combo
                    int tmp = solve(current, a);
                    tmp += solve(current, b);
                    for (int k = 0; k < n; k++) {
                        int c = adjList.get(k);
                        if (c != a && c != b && c != p) {
                            tmp += getDepth(current, c);
                        }
                    }
                    ans = Math.min(ans, tmp);
                }
            }
            memo.put(id, ans);
            // System.out.println("ans(" + p + "," + current + ")=" + ans);
            return ans;
        }

        int getDepth(int p, int current) {
            int id = getId(p, current);
            if (p >= 0 && depth.containsKey(id)) {
                return depth.get(id);
            }
            List<Integer> adjList = adj.get(current);
            int n = adjList.size();
            int res = 1;
            for (int i = 0; i < n; i++) {
                int a = adjList.get(i);
                if (a != p) {
                    res += getDepth(current, a);
                }
            }
            depth.put(id, res);
            return res;
        }

        static int getId(int p, int current) {
            return p * 1001 + current;
        }

    }

}
