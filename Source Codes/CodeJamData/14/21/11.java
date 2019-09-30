import java.io.*;
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

    private String[] strings;

    public A(InputReader reader) throws IOException {
        int n = reader.nextInt();
        strings = new String[n];
        for (int i = 0; i < n; i++) {
            strings[i] = reader.nextToken();
        }
    }

    private String solve() throws Exception {
        String common = norm(strings[0]);
        for (String x : strings) {
            if (!norm(x).equals(common)) {
                return "Fegla Won";
            }
        }
        int n = strings.length;
        int[] p = new int[n];
        int ans = 0;
        for (int chnum = 0; chnum < common.length(); chnum++) {
            char ch = common.charAt(chnum);
            int[] lens = new int[n];
            for (int i = 0; i < n; i++) {
                while (p[i] < strings[i].length() && strings[i].charAt(p[i]) == ch) {
                    p[i]++;
                    lens[i]++;
                }
            }
            ans += calc(lens);
        }
        return "" + ans;
    }

    private int calc(int[] lens) {
        int res = Integer.MAX_VALUE;
        int max = 0;
        for (int x : lens) {
            max = Math.max(max, x);
        }
        for (int target = 1; target <= max; target++) {
            int sum = 0;
            for (int x : lens) {
                sum += Math.abs(target - x);
            }
            res = Math.min(res, sum);
        }
        return res;
    }

    private String norm(String s) {
        StringBuilder res = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (res.length() == 0 || res.charAt(res.length() - 1) != ch) {
                res.append(ch);
            }
        }
        return res.toString();
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
