import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
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
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("alphabetcake.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("alphabetcake.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AlphabetCake solver = new AlphabetCake();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class AlphabetCake {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int r = in.nextInt();
            int c = in.nextInt();
            char[][] grid = new char[r][];
            for (int i = 0; i < r; i++) {
                grid[i] = in.nextToken().toCharArray();
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == '?') {
                        continue;
                    }
                    for (int k = j - 1; k >= 0 && grid[i][k] == '?'; k--) {
                        grid[i][k] = grid[i][j];
                    }
                    for (int k = j + 1; k < c && grid[i][k] == '?'; k++) {
                        grid[i][k] = grid[i][j];
                    }
                }
            }
            for (int i = 0; i < r; i++) {
                if (grid[i][0] == '?') {
                    continue;
                }
                for (int k = i - 1; k >= 0 && grid[k][0] == '?'; k--) {
                    System.arraycopy(grid[i], 0, grid[k], 0, c);
                }
                for (int k = i + 1; k < r && grid[k][0] == '?'; k++) {
                    System.arraycopy(grid[i], 0, grid[k], 0, c);
                }
            }
            out.println("Case #" + testNumber + ":");
            for (int i = 0; i < r; i++) {
                out.println(grid[i]);
            }
        }

    }

    static class InputReader {
        public BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            return nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}

