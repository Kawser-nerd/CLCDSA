import java.util.*;
import java.io.*;
/**
 *  @author citizen11
 *  AtCoder Regular Contest 78
 *  Task D - Fennec VS. Snuke
 */
public class Main {
    public static void main(String[] args) {
        Reader.init(System.in);
        try {
            int n = Reader.nextInt();
            List<int[]> A = new ArrayList<>();
            for (int i = 0; i < n-1; i++) {
                A.add(new int[] {Reader.nextInt(), Reader.nextInt()});
            }
            System.out.println(solve(n, A));
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static String solve(int n, List<int[]> A) {
        Map<Integer, List<Integer>> graph = constructGraph(n, A);
        int[] fenecDist = new int[n + 1];
        Arrays.fill(fenecDist, -1);
        int[] snukeDist = new int[n + 1];
        Arrays.fill(snukeDist, -1);
        dfs(graph, fenecDist, 1, 0);
        dfs(graph, snukeDist, n, 0);

        int[] fscore = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            if (fenecDist[i] <= snukeDist[i])
                fscore[i] = 1;
        }
        return Arrays.stream(fscore).sum() > n / 2 ? "Fennec" : "Snuke";
    }

    private static void dfs(Map<Integer, List<Integer>> graph, int[] dist, int start, int depth) {
        if (dist[start] > -1)
            return;
        dist[start] = depth;
        for (int i : graph.get(start)) {
            dfs(graph, dist, i, depth + 1);
        }
    }

    private static Map<Integer, List<Integer>> constructGraph(int n, List<int[]> A) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i <= n; i++) {
            graph.put(i, new ArrayList<Integer>());
        }
        for (int i = 0; i < A.size(); i++) {
            int[] edge = A.get(i);
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        return graph;
    }
}

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) {
        reader = new BufferedReader(
                     new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(
                   reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}