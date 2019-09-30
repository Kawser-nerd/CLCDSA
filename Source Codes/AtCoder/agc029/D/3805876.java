import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.util.Comparator;
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
        DGridGame solver = new DGridGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGridGame {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int h = in.ints(), w = in.ints(), n = in.ints();
            Map<Integer, List<Integer>> m = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int x = in.ints(), y = in.ints();
                if (y <= x) {
                    if (!m.containsKey(y)) {
                        m.put(y, new ArrayList<>());
                    }
                    m.get(y).add(x);
                }
            }
            for (List<Integer> e : m.values()) {
                e.sort(Comparator.naturalOrder());
            }
            int ans = h;
            int minx = 1;
            for (int i = 1; i <= w; i++) {
                //System.out.println("FOR " + i + " minx " + minx);
                int rx = h;
                if (m.containsKey(i)) {
                    for (Integer d : m.get(i)) {
                        if (d == minx) {
                            throw new RuntimeException();
                        } else if (d > minx) {
                            rx = d - 1;
                            //System.out.println("FOUND " + d);
                            if (minx == d + 1) {
                                ans = Math.min(ans, rx - 1);
                            } else {
                                ans = Math.min(ans, rx);
                            }
                            break;
                        }
                    }
                }
                if (minx == rx) {
                    break;
                }
                minx++;
                if (m.containsKey(i + 1)) {
                    while (m.get(i + 1).contains(minx)) {
                        minx++;
                    }
                }
                if (minx > rx) {
                    break;
                }
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

    }
}