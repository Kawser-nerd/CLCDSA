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
        AWannaGoBackHome solver = new AWannaGoBackHome();
        solver.solve(1, in, out);
        out.close();
    }

    static class AWannaGoBackHome {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            String s = in.string();
            int mask = 0;
            for (char c : s.toCharArray()) {
                switch (c) {
                    case 'N':
                        mask |= 0b0001;
                        break;
                    case 'S':
                        mask |= 0b0010;
                        break;
                    case 'E':
                        mask |= 0b0100;
                        break;
                    case 'W':
                        mask |= 0b1000;
                        break;
                }
            }
            if (mask == 3 || mask == 12 || mask == 15) {
                out.println(YES);
            } else {
                out.println(NO);
            }
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