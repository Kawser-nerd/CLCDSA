import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
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

    private char[] ch;

    public C(InputReader reader) throws IOException {
        ch = reader.nextToken().toCharArray();
    }

    private String solve() throws Exception {
        int n = ch.length;
        int[][] d = new int[n + 1 + 100][5];
        for (int[] v : d) {
            Arrays.fill(v, Integer.MAX_VALUE);
        }
        d[0][4] = 0;
        for (int consumed = 0; consumed < n; consumed++) {
            for (int unchanged = 0; unchanged < 5; unchanged++) {
                if (d[consumed][unchanged] < Integer.MAX_VALUE) {
                    for (char[] word : DICTIONARY) {
                        int nextIndexAllowedToChange = 4 - unchanged;
                        int newUnchanged = unchanged;
                        int countChanges = 0;
                        boolean good = word.length + consumed <= n;
                        for (int i = 0; i < word.length && good; i++) {
                            newUnchanged++;
                            if (word[i] != ch[consumed + i]) {
                                newUnchanged = 0;
                                if (i < nextIndexAllowedToChange) {
                                    good = false;
                                    break;
                                }
                                nextIndexAllowedToChange = i + 5;
                                countChanges++;
                            }
                        }
                        if (good) {
                            newUnchanged = Math.min(newUnchanged, 4);
                            if (d[consumed + word.length][newUnchanged] > d[consumed][unchanged] + countChanges) {
                                d[consumed + word.length][newUnchanged] = d[consumed][unchanged] + countChanges;
                            }
                        }
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int x : d[n]) {
            ans = Math.min(ans, x);
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

    private static char[][] DICTIONARY;

    private static void readDictionary() throws Exception {
        List<String> dic = new ArrayList<>();
        try (InputReader reader = new InputReader("garbled_email_dictionary.txt")) {
            String token;
            while ((token = reader.in.readLine()) != null) {
                dic.add(token.trim());
            }
            DICTIONARY = new char[dic.size()][];
            for (int i = 0; i < dic.size(); i++) {
                DICTIONARY[i] = dic.get(i).toCharArray();
            }
        } finally {
        }
    }

    public static void main(String[] args) throws Exception {
        readDictionary();
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
