import java.io.*;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class B {

    private static final String TASK_LETTER = "B";

    private static enum TaskSize {
        sample,
        small_attempt0,
        large
    }

    private int n;
    private int x;
    private int y;

    public B(InputReader reader) throws IOException {
        n = reader.nextInt();
        x = reader.nextInt();
        y = reader.nextInt();
    }

    private static class Vector {
        final int x;
        final int y;

        private Vector(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vector vector = (Vector) o;
            return x == vector.x && y == vector.y;
        }

        @Override
        public int hashCode() {
            return 31 * x + y;
        }

        @Override
        public String toString() {
            return x + "," + y;
        }
    }

    private String solve() throws Exception {
        int k = 1;
        while ((k + 2) * (k + 3) / 2 <= n) {
            k += 2;
        }
        int rest = n - k * (k + 1) / 2;
        Map<Vector, Double> next = new HashMap<>();
        next.put(new Vector(0, 0), 1.0);
        while (rest-- > 0) {
            Map<Vector, Double> prev = next;
            next = new HashMap<>();
            for (Map.Entry<Vector, Double> entry : prev.entrySet()) {
                Vector v = entry.getKey();
                if (v.x == k + 1) {
                    add(next, new Vector(v.x    , v.y + 1), entry.getValue());
                } else if (v.y == k + 1) {
                    add(next, new Vector(v.x + 1, v.y    ), entry.getValue());
                } else {
                    add(next, new Vector(v.x + 1, v.y    ), entry.getValue() * 0.5);
                    add(next, new Vector(v.x    , v.y + 1), entry.getValue() * 0.5);
                }
            }
        }
        x = Math.abs(x);
        double ans = 0.0;
        if ((x + y) < k) {
            ans = 1.0;
        } else if (x + y == k + 1) {
            for (Map.Entry<Vector, Double> entry : next.entrySet()) {
                if (y < entry.getKey().y) {
                    ans += entry.getValue();
                }
            }
        }
        return String.format("%.6f", ans);
    }

    private void add(Map<Vector, Double> map, Vector key, double value) {
        if (!map.containsKey(key)) {
            map.put(key, value);
        } else {
            map.put(key, map.get(key) + value);
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

        @Override
        public void close() throws Exception {
            in.close();
        }

    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        for (final TaskSize taskSize : TaskSize.values()) {
            String inName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".in";
            String outName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".out";
            String ansName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".ans";

            try (InputReader reader = new InputReader(inName); PrintWriter writer = new PrintWriter(outName)) {
                ExecutorService executorService = Executors.newFixedThreadPool(6);

                int testCases = reader.nextInt();
                final String[] result = new String[testCases];
                for (int i = 0; i < testCases; i++) {
                    final B solution = new B(reader);
                    final int testCase = i;
                    executorService.submit(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                result[testCase] = solution.solve();
                            } catch (Exception e) {
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
