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
import java.util.BitSet;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
            int m = in.nextInt();

            boolean[][] edges = new boolean[n][n];
            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                edges[from][to] = true;
                edges[to][from] = true;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    edges[i][j] = !edges[i][j];
                }
            }

            List<Integer> list1 = new ArrayList<>();
            List<Integer> list2 = new ArrayList<>();
            boolean[] used = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (used[i]) continue;

                int[] group = new int[n];
                group[i] = 1;
                ArrayDeque<Integer> q = new ArrayDeque<>();
                q.add(i);
                int cnt1 = 1;
                int cnt2 = 0;
                used[i] = true;
                while (!q.isEmpty()) {
                    int x = q.poll();

                    for (int j = 0; j < n; j++) {
                        if (j == x) continue;
                        if (edges[x][j]) {
                            if (group[j] == 0) {
                                group[j] = -group[x];

                                if (group[j] == 1) cnt1++;
                                else cnt2++;

                                q.add(j);
                                used[j] = true;
                            } else if (group[j] == group[x]) {
                                out.println(-1);
                                return;
                            }
                        }
                    }
                }
                list1.add(cnt1);
                list2.add(cnt2);
            }

            BitSet bitSet = new BitSet();
            bitSet.set(n);
            for (int i = 0; i < list1.size(); i++) {
                BitSet bitSet1 = bitSet.get(list1.get(i), bitSet.size());
                BitSet bitSet2 = bitSet.get(list2.get(i), bitSet.size());

                bitSet1.or(bitSet2);
                bitSet = bitSet1;
            }

            int min = Integer.MAX_VALUE;
            for (int i = 0; i <= n; i++) {
                if (bitSet.get(i)) {
                    int tmp = i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2;
                    min = Math.min(min, tmp);
                }
            }

            out.println(min);
        }

    }

    static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }
}