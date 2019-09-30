import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            int[] a = in.ints(n);
            int ans = Integer.MIN_VALUE;
            for (int firstChoice = 0; firstChoice < n; firstChoice++) {
                int firstMax = Integer.MIN_VALUE;
                int secondMax = Integer.MIN_VALUE;
                for (int secondChoice = 0; secondChoice < n; secondChoice++) {
                    if (firstChoice == secondChoice) {
                        continue;
                    }
                    int l = Math.min(firstChoice, secondChoice);
                    int r = Math.max(firstChoice, secondChoice);
                    int firstScore = 0;
                    int secondScore = 0;
                    for (int k = l; k <= r; k++) {
                        if ((k - l) % 2 == 0) {
                            firstScore += a[k];
                        } else {
                            secondScore += a[k];
                        }
                    }
                    if (secondScore > secondMax) {
                        secondMax = secondScore;
                        firstMax = firstScore;
                    }
                }
                ans = Math.max(firstMax, ans);
            }
            out.println(ans);
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

        public int[] ints(int length) {
            return IntStream.range(0, length).map(x -> ints()).toArray();
        }

    }
}