import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author littlesheep
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        int[] stones;
        Edge[] first;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            stones = new int[n];
            first = new Edge[n];
            for (int i = 0; i < n; ++i) {
                stones[i] = in.nextInt();
            }
            int[] degree = new int[n];
            for (int i = 0; i < n - 1; ++i) {
                int from, to;
                from = in.nextInt() - 1;
                to = in.nextInt() - 1;
                new Edge(from, to);
                new Edge(to, from);
                ++degree[from];
                ++degree[to];
            }

            if (n == 2) {
                out.println(stones[0] == stones[1] ? "YES" : "NO");
                return;
            }

            int root = -1;
            for (int i = 0; i < n; ++i) {
                if (degree[i] > 1) {
                    root = i;
                    break;
                }
            }
            assert root != -1;
            System.err.println("root = " + root);
            out.print(dfs(root, -1) == 0 ? "YES" : "NO");
        }

        private int dfs(int x, int fa) {
            ArrayList<Integer> subtrees = new ArrayList<>();
            boolean isLeaf = true;
            long sum = 0;
            for (Edge e = first[x]; e != null; e = e.next) {
                if (e.to == fa) {
                    continue;
                }
                isLeaf = false;
                int number = dfs(e.to, x);
                if (number == -1) {
                    return -1;
                }
                subtrees.add(number);
                sum += number;
            }

            if (isLeaf) {
                return stones[x];
            }
            if (sum < stones[x]) {
                return -1;
            }

            Collections.sort(subtrees);
            long otherSum = 0;
            for (int i = 0; i < subtrees.size() - 1; ++i) {
                otherSum += subtrees.get(i);
            }

            long internalRequirement = sum - stones[x];
            long externamRequirement = stones[x] - internalRequirement;

            if (internalRequirement < 0 || externamRequirement < 0) {
                return -1;
            }


            long pairs = sum / 2;
            if (otherSum < subtrees.get(subtrees.size() - 1)) {
                pairs = otherSum;
            }
//        System.err.println("x = " + x + " pairs = " + pairs + " internal = " + internalRequirement + " external = " + externamRequirement);
            if (pairs < internalRequirement) {
                return -1;
            }

            return (int) externamRequirement;
        }

        class Edge {
            int to;
            Edge next;

            Edge(int from, int to) {
                this.to = to;
                this.next = first[from];
                first[from] = this;
            }

        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}