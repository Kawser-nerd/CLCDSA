import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int numPeople = in.nextInt(), numSports = in.nextInt();
            int[][] A = new int[numPeople][numSports];
            for (int person = 0; person < numPeople; ++person) {
                for (int i = 0; i < numSports; ++i)
                    A[person][i] = in.nextInt() - 1;
            }
            boolean[] removed = new boolean[numSports];
            int[] cnt = new int[numSports];

            int answer = numPeople;

            for (int i = 0; i < numSports; ++i) {
                Arrays.fill(cnt, 0);
                for (int person = 0; person < numPeople; ++person) {
                    for (int j = 0; j < numSports; ++j)
                        if (!removed[A[person][j]]) {
                            ++cnt[A[person][j]];
                            break;
                        }
                }
                int max = 0, idMax = -1;
                for (int sport = 0; sport < numSports; ++sport) {
                    if (cnt[sport] > max) {
                        max = cnt[sport];
                        idMax = sport;
                    }
                }
                answer = Math.min(answer, max);
                removed[idMax] = true;
            }

            out.println(answer);
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