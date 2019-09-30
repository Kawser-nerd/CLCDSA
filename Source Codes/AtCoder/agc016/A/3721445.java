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
        AShrinking solver = new AShrinking();
        solver.solve(1, in, out);
        out.close();
    }

    static class AShrinking {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            String s = in.string();
            int[] n = new int[26];
            for (char c : s.toCharArray()) {
                n[c - 'a']++;
            }
            int min = 100000;
            for (char c = 'a'; c <= 'z'; c++) {
                String t = s;
                int ans = 0;
                while (t.chars().distinct().count() > 1) {
                    char[] ns = new char[t.length() - 1];
                    for (int i = 0; i < ns.length; i++) {
                        ns[i] = t.charAt(i) == c || t.charAt(i + 1) == c ? c : t.charAt(i);
                    }
                    t = String.valueOf(ns);
                    ans++;
                }
                min = Math.min(min, ans);
            }
            out.println(min);
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

    }
}