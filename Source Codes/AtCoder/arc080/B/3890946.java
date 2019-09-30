import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.stream.Stream;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        DGridColoring solver = new DGridColoring();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGridColoring {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int h = in.ints(), w = in.ints();
            int n = in.ints();
            int[] a = in.ints(n);
            int[][] c = new int[h][w];
            int offset = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < a[i]; j++) {
                    int index = offset + j;
                    //System.out.println(index);
                    int y = index / w;
                    if (y % 2 == 0) {
                        c[y][index % w] = i + 1;
                    } else {
                        c[y][w - (index % w) - 1] = i + 1;
                    }
                }
                offset += a[i];
            }
            Arrays.stream(c)
                    .map(x -> IntStream.of(x).mapToObj(Integer::toString).collect(Collectors.joining(" ")))
                    .forEach(out::println);
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