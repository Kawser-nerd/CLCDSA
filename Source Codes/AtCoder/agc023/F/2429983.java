import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static int nextBlockId = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] value = new int[n];
            int[] parent = new int[n];
            parent[0] = -1;

            TreeSet<TaskF.Block>[] blocks = new TreeSet[n];
            for (int i = 1; i < n; ++i) {
                parent[i] = in.nextInt() - 1;
            }
            for (int i = 0; i < n; ++i) value[i] = in.nextInt();
            TreeSet<TaskF.Block> res = null;
            for (int i = n - 1; i >= 0; --i) {
                TreeSet<TaskF.Block> cur = blocks[i];
                blocks[i] = null;
                if (cur == null) cur = new TreeSet<>();
                TaskF.Block first = new TaskF.Block(value[i] == 0 ? 1 : 0, value[i] == 1 ? 1 : 0, 0);
                while (!cur.isEmpty() && first.compareTo(cur.first()) > 0) {
                    TaskF.Block eat = cur.pollFirst();
                    first.inversions += eat.inversions;
                    first.inversions += first.ones * eat.zeros;
                    first.ones += eat.ones;
                    first.zeros += eat.zeros;
                }
                cur.add(first);
                if (i == 0) {
                    res = cur;
                } else {
                    TreeSet<TaskF.Block> other = blocks[parent[i]];
                    if (other != null) {
                        if (other.size() < cur.size()) {
                            cur.addAll(other);
                        } else {
                            other.addAll(cur);
                            cur = other;
                        }
                    }
                    blocks[parent[i]] = cur;
                }
            }
            long ones = 0;
            long sum = 0;
            for (TaskF.Block b : res) {
                sum += b.inversions;
                sum += ones * b.zeros;
                ones += b.ones;
            }
            out.println(sum);
        }

        static class Block implements Comparable<TaskF.Block> {
            int id;
            long zeros;
            long ones;
            long inversions;

            public Block(long zeros, long ones, long inversions) {
                id = ++nextBlockId;
                this.zeros = zeros;
                this.ones = ones;
                this.inversions = inversions;
            }


            public int compareTo(TaskF.Block o) {
                int z = Long.compare(ones * o.zeros, zeros * o.ones);
                if (z == 0) z = Integer.compare(id, o.id);
                return z;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.