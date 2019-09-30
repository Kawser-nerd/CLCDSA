

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class TSP {
    static BufferedReader stdin = new BufferedReader(
            new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");

    // Read next input-token as string.
    static String readString() throws Exception {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(stdin.readLine());
        }
        return st.nextToken();
    }

    // Read next input-token as integer.
    static int readInt() throws Exception {
        return Integer.parseInt(readString());
    }

    // Read next input-token as double.
    static double readDouble() throws Exception {
        return Double.parseDouble(readString());
    }

    public static void main(String[] args) throws Exception {
        int T = readInt();
        for (int t = 1; t <= T; t++) {
            System.out.printf("Case #%d: ", t);
            solve();
        }
    }

    static ArrayList<Set<Integer>> edges;
    static void solve() throws Exception {
        int N = readInt();
        int M = readInt();
        ArrayList<Integer> zip = new ArrayList<>();
        int minzip = Integer.MAX_VALUE;
        int minidx = -1;
        edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edges.add(new HashSet<Integer>());
            int newzip = readInt();
            if (newzip < minzip) {
                minzip = newzip;
                minidx = i;
            }
            zip.add(newzip);
        }
        for (int j = 0; j < M; j++) {
            int from = readInt() - 1;
            int to = readInt() - 1;
            edges.get(from).add(to);
            edges.get(to).add(from);
        }
        ArrayList<Integer> visited = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            visited.add(i, 0);
        }
        visited.set(minidx, 1);
        String ziprow = Integer.toString(minzip);
        ArrayList<Integer> stack = new ArrayList<>();
        stack.add(minidx);

        for (int steps = 0; steps < N - 1; steps++) {
            int bestzip = Integer.MAX_VALUE;
            int bestidx = -1;
            HashSet<Integer> triedidx = new HashSet<>();
            for (int i = stack.size() - 1; i >= 0; i--) {
                for (int edge : edges.get(stack.get(i))) {
                    if (visited.get(edge) == 1 || triedidx.contains(edge)) {
                        continue;
                    }
                    if (zip.get(edge) > bestzip) {
                        continue;
                    }
                    if (poll(visited, stack, edge, N - 1 - steps, i)) {
                        bestzip = zip.get(edge);
                        bestidx = edge;
                    }
                }
            }
            for (int i = stack.size() - 1; i >= 0; i--) {
                if (edges.get(stack.get(i)).contains(bestidx)) {
                    ziprow += Integer.toString(bestzip);
                    visited.set(bestidx, 1);
                    stack.add(bestidx);
                    break;
                }
                stack.remove(stack.size() - 1);
            }
        }
        System.out.printf("%s\n", ziprow);

    }

    private static boolean poll(ArrayList<Integer> visited, ArrayList<Integer> stack, int newedge,
            int steps, int stackdepth) {
        List<Integer> vis = new ArrayList<>(visited);
        List<Integer> sta = new ArrayList<>(stack);
        sta = sta.subList(0, stackdepth + 1);
        sta.add(newedge);
        vis.set(newedge, 1);
        steps--; // TODO?
        while (steps != 0) {
            if (sta.size() == 0)
                return false;
            int top = sta.get(sta.size() - 1);
            for (int edge : edges.get(top)) {
                if (vis.get(edge) == 1)
                    continue;
                vis.set(edge, 1);
                steps--;
                sta.add(edge);
                sta.add(edge);
                break;
            }
            sta.remove(sta.size() - 1);
        }
        return true;
    }
}
