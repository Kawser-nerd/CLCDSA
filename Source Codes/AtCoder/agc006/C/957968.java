import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by fcdkbear on 15.10.16.
 */
public class Main {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        new Task().solve(in, out);
        out.close();
    }


    static class Task {

        public void solve(InputReader in, PrintWriter out) {

            int n = in.nextInt();
            int[] x = new int[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
            }
            int[] d = new int[n - 1];
            for (int i = 0; i < n - 1; ++i) {
                d[i] = x[i + 1] - x[i];
            }
            int[] permutation = new int[n - 1];
            for (int i = 0; i < n - 1; ++i) {
                permutation[i] = i;
            }
            int m = in.nextInt();
            long k = in.nextLong();
            for (int i = 0; i < m; ++i) {
                int rabbitIndex = in.nextInt();
                rabbitIndex--;
                int temp = permutation[rabbitIndex - 1];
                permutation[rabbitIndex - 1] = permutation[rabbitIndex];
                permutation[rabbitIndex] = temp;
            }
            int[] movesTo = new int[n - 1];
            for (int i = 0; i < permutation.length; ++i) {
                movesTo[permutation[i]] = i;
            }
            int[] positions = new int[n - 1];
            for (int i = 0; i < n - 1; ++i) {
                positions[i] = i;
            }
            while (k > 0) {
                if (k % 2 == 1) {
                    int[] nextPositions = new int[n - 1];
                    for (int i = 0; i < positions.length; ++i) {
                        nextPositions[movesTo[i]] = positions[i];
                    }
                    for (int i = 0; i < positions.length; ++i) {
                        positions[i] = nextPositions[i];
                    }
                }
                int[] nextMovesTo = new int[n - 1];
                for (int i = 0; i < n - 1; ++i) {
                    nextMovesTo[i] = movesTo[movesTo[i]];
                }
                for (int i = 0; i < n - 1; ++i) {
                    movesTo[i] = nextMovesTo[i];
                }
                k /= 2;
            }
            long res = x[0];
            for (int i = 0; i < n; ++i) {
                out.println(res);
                if (i != n - 1) {
                    res += d[positions[i]];
                }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }

}