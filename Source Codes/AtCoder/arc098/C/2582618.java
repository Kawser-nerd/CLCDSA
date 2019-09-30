import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // ??????????
            int n = in.nextInt();
            int k = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[n + 1];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                List<Integer> candidates = new ArrayList<>();
                List<Integer> list = new ArrayList<>();
                for (int j = 0; j <= n; j++) {
                    if (a[j] < a[i]) {
                        if (!list.isEmpty()) {
                            if (list.size() - k >= 0) {
                                Collections.sort(list);
                                for (int l = 0; l < list.size() - k + 1; l++) {
                                    candidates.add(list.get(l));
                                }
                            }
                            list = new ArrayList<>();
                        }
                    } else {
                        list.add(a[j]);
                    }
                }

                if (candidates.size() < q) {
                    continue;
                }

                Collections.sort(candidates);
                ans = Math.min(ans, candidates.get(q - 1) - a[i]);
            }

            out.println(ans);
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}