import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static ArrayList<Integer> findPath(int[][] capacity, int s, int t) {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(s);
        int V = capacity.length;
        int[] pred = new int[V];
        Arrays.fill(pred, -1);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 0; i < V; i++) {
                if (capacity[cur][i] == 0 || pred[i] != -1) {
                    continue;
                }
                pred[i] = cur;
                if (i == t) {
                    return createPath(pred, s, t);
                }
                q.add(i);
            }
        }
        return null;
    }

    private static ArrayList<Integer> createPath(int[] pred, int s, int t) {
        ArrayList<Integer> path = new ArrayList<>();
        path.add(t);
        while (pred[t] != s) {
            t = pred[t];
            path.add(t);
        }
        Collections.reverse(path);
        return path;
    }

    public static int[][] flow(int[][] capacity, int s, int t) {
        int V = capacity.length;
        int[][] flow = new int[V][V];
        while (true) {
            ArrayList<Integer> path = findPath(capacity, s, t);
            if (path == null) {
                for (int i = 0; i < V; i++) {
                    for (int j = i + 1; j < V; j++) {
                        if (flow[i][j] > 0 && flow[j][i] > 0) {
                            flow[i][j] = Math.max(flow[i][j] - flow[j][i], 0);
                            flow[j][i] = Math.max(flow[j][i] - flow[i][j], 0);
                        }
                    }
                }
                return flow;
            }
            int prev = s;
            int min = Integer.MAX_VALUE;
            for (int i : path) {
                min = Math.min(min, capacity[prev][i]);
                prev = i;
            }
            prev = s;
            for (int i : path) {
                capacity[prev][i] -= min;
                capacity[i][prev] += min;
                flow[prev][i] += min;
                prev = i;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] capacity = new int[N * 2 + 2][N * 2 + 2];
        int s = 0, t = N * 2 + 1;
        ArrayList<Integer> as = new ArrayList<>();
        ArrayList<Integer> bs = new ArrayList<>();
        ArrayList<Integer> cs = new ArrayList<>();
        ArrayList<Integer> ds = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            as.add(sc.nextInt());
            bs.add(sc.nextInt());
        }
        for (int i = 0; i < N; i++) {
            cs.add(sc.nextInt());
            ds.add(sc.nextInt());
        }
        for (int i = 0; i < N; i++) {
            capacity[s][i + 1] = 1;
            capacity[i + 1 + N][t] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (as.get(i) < cs.get(j) && bs.get(i) < ds.get(j)) {
                    capacity[i + 1][j + 1 + N] = 1;
                }
            }
        }
        int[][] flow = flow(capacity, s, t);
        System.out.println(IntStream.of(flow[0]).sum());
    }
}