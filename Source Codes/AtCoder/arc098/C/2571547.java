import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.LinkedList;
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
            int N = in.nextInt();
            int K = in.nextInt();
            int Q = in.nextInt();

            int[] A = new int[N];

            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
            }

            int ans = Integer.MAX_VALUE;

            for (int X : A) {
                ans = Math.min(ans, find(A, X, K, Q));
            }

            out.println(ans);
        }

        private int find(int[] A, int X, int K, int Q) {
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            int N = A.length;

            int left = 0, right;

            while ((right = findLess(A, left, X)) != -1) {
                pq.addAll(smallest(A, left, right, K));
                left = right + 1;
            }

            pq.addAll(smallest(A, left, N, K));

            if (pq.size() < Q) {
                return Integer.MAX_VALUE;
            }

            while (Q-- > 1) pq.poll();

            return pq.poll() - X;
        }

        private Queue<Integer> smallest(int[] A, int start, int end, int K) {
            PriorityQueue<Integer> pq = new PriorityQueue<>();

            int length = end - start;
            int limit = length - K + 1;

            for (int i = start; i < end; i++) {
                pq.add(A[i]);
            }

            Queue<Integer> ans = new LinkedList<>();

            for (int i = 0; i < limit; i++) {
                ans.add(pq.poll());
            }

            return ans;
        }

        private int findLess(int[] a, int start, int X) {
            for (int i = start; i < a.length; i++) {
                if (a[i] < X) return i;
            }
            return -1;
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
}