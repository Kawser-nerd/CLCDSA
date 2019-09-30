import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class C {

    private static final String TASK_LETTER = "C";

    private static enum TaskSize {
        sample,
        small_attempt0,
        large
    }


    private int n;
    private String[] zip;
    private int[] parent;
    private int[] dist;
    private boolean[] active;
    private int[][] a;

    public C(InputReader reader) throws IOException {
        n = reader.nextInt();
        int m = reader.nextInt();
        zip = new String[n];
        parent = new int[n];
        dist = new int[n];
        a = new int[n][n];
        for (int i = 0; i < n; i++) {
            zip[i] = reader.nextToken();
        }
        for (int i = 0; i < m; i++) {
            int x = reader.nextInt() - 1;
            int y = reader.nextInt() - 1;
            a[x][y] = 1;
            a[y][x] = 1;
        }
    }

    private String solve() throws Exception {
        int start = 0;
        for (int i = 1; i < n; i++) {
            if (zip[start].compareTo(zip[i]) > 0) {
                start = i;
            }
        }
        active = new boolean[n];
        Arrays.fill(active, false);
        StringBuilder res = new StringBuilder();
        res.append(zip[start]);
        Arrays.fill(dist, -1);
        Arrays.fill(parent, -1);
        dist[start] = 0;
        active[start] = true;
        for (int iter = 1; iter < n; iter++) {
            int nextVertex = -1;
            int nextFrom = -1;
            for (int candidate = 0; candidate < n; candidate++) {
                if (dist[candidate] < 0 && (nextVertex < 0 || zip[nextVertex].compareTo(zip[candidate]) > 0)) {
                    int from = -1;
                    for (int i = 0; i < n; i++) {
                        if (a[i][candidate] > 0 && active[i] && (from < 0 || dist[i] > dist[from])) {
                            from = i;
                        }
                    }
                    if (from >= 0 && connectedAllowingUnusedAndPathFrom(from)) {
                        nextVertex = candidate;
                        nextFrom = from;
                    }
                }
            }
            if (nextVertex < 0) {
                throw null;
            }
            res.append(zip[nextVertex]);
            parent[nextVertex] = nextFrom;
            dist[nextVertex] = dist[nextFrom] + 1;
            Arrays.fill(active, false);
            while (nextVertex >= 0) {
                active[nextVertex] = true;
                nextVertex = parent[nextVertex];
            }
        }
        return res.toString();
    }

    private int[] visited;

    private boolean connectedAllowingUnusedAndPathFrom(int from) {
        visited = new int[n];
        for (int i = 0; i < n; i++) {
            if (dist[i] >= 0) {
                visited[i] = -1;
            }
        }
        int z = from;
        while (from >= 0) {
            visited[from] = 0;
            from = parent[from];
        }
        rec(z);
        for (int x : visited) {
            if (x == 0) {
                return false;
            }
        }
        return true;
    }

    private void rec(int v) {
        for (int i = 0; i < n; i++) {
            if (a[v][i] > 0 && visited[i] == 0) {
                visited[i] = 1;
                rec(i);
            }
        }
    }

    public static class InputReader implements AutoCloseable {

        private final BufferedReader in;
        private StringTokenizer tokenizer = new StringTokenizer("");

        public InputReader(String filename) throws FileNotFoundException {
            this.in = new BufferedReader(new FileReader(filename));
        }

        public String nextToken() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }

        @Override
        public void close() throws Exception {
            in.close();
        }

    }

    public static void main(String[] args) throws Exception {
        for (final TaskSize taskSize : TaskSize.values()) {
            String inName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".in";
            String outName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".out";
            String ansName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".ans";

            try (InputReader reader = new InputReader(inName); PrintWriter writer = new PrintWriter(outName)) {
                ExecutorService executorService = Executors.newFixedThreadPool(6);

                int testCases = reader.nextInt();
                final String[] result = new String[testCases];
                for (int i = 0; i < testCases; i++) {
                    final C solution = new C(reader);
                    final int testCase = i;
                    executorService.submit(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                result[testCase] = solution.solve();
                            } catch (Exception e) {
                                e.printStackTrace();
                                throw new RuntimeException("Failed to solve test case=" + taskSize + "." + testCase);
                            }
                        }
                    });
                }
                executorService.shutdown();
                executorService.awaitTermination(10, TimeUnit.MINUTES);

                for (int testCase = 0; testCase < testCases; testCase++) {
                    writer.println("Case #" + (testCase + 1) + ": " + result[testCase]);
                    if (result[testCase] == null) {
                        throw new RuntimeException("No result for test case=" + taskSize + "." + testCase);
                    }
                }
            } catch (FileNotFoundException e) {
                // ignore
            }
            new ProcessBuilder("fc", outName, ansName).redirectOutput(ProcessBuilder.Redirect.INHERIT).start();
        }
    }
}
