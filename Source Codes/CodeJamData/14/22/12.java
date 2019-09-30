import java.io.*;
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

    private int a;
    private int b;
    private int k;

    public B(InputReader reader) throws IOException {
        a = reader.nextInt();
        b = reader.nextInt();
        k = reader.nextInt();
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
    }

    private String solve() throws Exception {
        long res = 0;

        int[] prefixes = new int[Integer.bitCount(b)];
        int cnt = 0;
        for (int prefix = 30; prefix >= 0; prefix--) {
            if ((b & (1 << prefix)) != 0) {
                prefixes[cnt++] = prefix;
            }
        }

        for (int first = 0; first < a; first++) {
            if (first < k) {
                res += b;
            } else {
                for (int prefix : prefixes) {
                    int prefixpow2 = 1 << prefix;
                    int sufix111 = prefixpow2 - 1;
                    int sufix000 = ~sufix111;
                    int prefix0111 = (b & sufix000) - 1;
                    if ((first & prefix0111) < k) {
                        res += prefixpow2;
                    } else {
                        int prefix0000 = (b & sufix000) - prefixpow2;
                        if ((first & prefix0000) == (k & sufix000)) {
                            for (int i = sufix111; i >= 0; i--) {
                                if ((first & (prefix0000 | i)) < k) {
                                    res++;
                                }
                            }
                        }
                    }
                }
            }

        }
        String ans = "" + res;

//        if (!solveNaive(a, b, k).equals(ans)) {
//            throw null;
//        }

        return ans;
    }

    private static String solveNaive(int a, int b, int k) throws Exception {
        int res = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if ((i & j) < k) {
                    res++;
                }
            }
        }
        return "" + res;
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
                ExecutorService executorService = Executors.newFixedThreadPool(4);

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
