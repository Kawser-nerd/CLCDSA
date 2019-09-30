import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        ADigitSum2 solver = new ADigitSum2();
        solver.solve(1, in, out);
        out.close();
    }

    static class ADigitSum2 {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            String n = in.string();
            int ans = 0;
            boolean filled = true;
            for (int i = 1; i < n.length(); i++) {
                if (n.charAt(i) != '9') {
                    filled = false;
                }
                ans += 9;
            }
            ans += Integer.parseInt(n.substring(0, 1));
            if (!filled) {
                ans -= 1;
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

    }
}