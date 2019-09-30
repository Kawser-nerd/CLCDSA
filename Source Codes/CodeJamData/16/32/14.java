import java.io.*;
import java.util.*;

public class Slides {

    public void solve() {
        int b = in.nextInt();
        long m = in.nextLong();

        if ((1L << (b - 2)) < m) {
            out.println("IMPOSSIBLE");
            return;
        }
        out.println("POSSIBLE");

        boolean[][] matrix = new boolean[b][b];

        for (int i = 1; i < b; i++) {
            for (int j = i + 1; j < b; j++) {
                matrix[i][j] = true;
            }
        }

        for (int i = 1; i < b; i++) {
            long cnt = (i == b - 1) ? 1 : (1L << (b - 2 - i));
            if (m >= cnt) {
                m -= cnt;
                matrix[0][i] = true;
            }
        }

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b;j++) {
                out.print(matrix[i][j] ? '1' : '0');

            }
            out.println();
        }
    }

    public void run() {
        try {
            in = new FastScanner("input.txt");
            out = new PrintWriter("output.txt");
            int tests = in.nextInt();
            for (int i = 1; i <= tests; i++) {
                long time = System.currentTimeMillis();
                out.printf("Case #%d: ", i);
                solve();
                System.err.printf("Solved case #%d in %d ms\n", i, System.currentTimeMillis() - time);
            }
            out.close();
        } catch (FileNotFoundException e) {
        }
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new Slides().run();
    }
}
