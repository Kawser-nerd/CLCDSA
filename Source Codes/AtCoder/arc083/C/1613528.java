import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
            int n = in.nextInt();

            int[] parents = new int[n];
            List<List<Integer>> childlen = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                childlen.add(new ArrayList<>());
            }
            parents[0] = -1;
            for (int i = 1; i < n; i++) {
                parents[i] = in.nextInt() - 1;
                childlen.get(parents[i]).add(i);
            }

            int[] sumScore = in.nextIntArray(n);

            int[] minWhite = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                int min = 0;
                for (int child : childlen.get(i)) {
                    min += Math.min(minWhite[child], sumScore[child]);
                }
                if (min > sumScore[i]) {
                    out.println("IMPOSSIBLE");
                    return;
                }

                int sum = 0;
                for (int child : childlen.get(i)) {
                    sum += minWhite[child];
                    sum += sumScore[child];
                }

                TreeSet<Integer> set = new TreeSet<>();
                set.add(0);
                for (int child : childlen.get(i)) {
                    TreeSet<Integer> nextSet = new TreeSet<>();
                    for (int score : set) {
                        if (score + sumScore[child] <= sumScore[i]) {
                            nextSet.add(score + sumScore[child]);
                        }
                        if (score + minWhite[child] <= sumScore[i]) {
                            nextSet.add(score + minWhite[child]);
                        }
                    }
                    set = nextSet;
                }

                minWhite[i] = sum - set.last();
            }

            out.println("POSSIBLE");
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

        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}