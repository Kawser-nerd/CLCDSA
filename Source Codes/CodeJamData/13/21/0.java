import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class A {

    private static final String TASK_LETTER = "A";

    private static enum TaskSize {
        sample,
        small_attempt0,
        large
    }

    private int n;
    private int me;
    private int[] a;

    public A(InputReader reader) throws IOException {
        me = reader.nextInt();
        n = reader.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = reader.nextInt();
        }
    }

    private String solve() throws Exception {
        Arrays.sort(a);
        int[] minMoves = new int[n + 1];
        int[] ourSize = new int[n + 1];
        minMoves[0] = 0; // +n
        ourSize[0] = me;
        int ans = n;
        if (me > 1) {
            for (int d = 1; d <= n; d++) {
                int size = ourSize[d - 1];
                minMoves[d] = minMoves[d - 1];
                while (size <= a[d - 1]) {
                    size += size - 1;
                    minMoves[d]++;
                }
                size += a[d - 1];
                ourSize[d] = size;
                if (ans > minMoves[d] + n - d) {
                    ans = minMoves[d] + n - d;
                }
            }
        }
        return "" + ans;
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
                    final A solution = new A(reader);
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
