import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
import java.util.stream.Stream;
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
        AShikAndStone solver = new AShikAndStone();
        solver.solve(1, in, out);
        out.close();
    }

    static class AShikAndStone {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int h = in.ints(), w = in.ints();
            String[] a = in.string(h);
            int c = 0;
            for (String row : a) {
                for (char column : row.toCharArray()) {
                    if (column == '#') {
                        c++;
                    }
                }
            }
            if (c == h + w - 1) {
                out.println("Possible");
            } else {
                out.println("Impossible");
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

        public String[] string(int length) {
            return IntStream.range(0, length).mapToObj(x -> string()).toArray(String[]::new);
        }

        public int ints() {
            return Integer.parseInt(string());
        }

    }
}