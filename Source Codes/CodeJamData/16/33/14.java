import java.io.*;
import java.util.*;

public class FashionSmall {

    int[] max;
    int[][][] count;
    int k;

    List<String> best;

    void go(int a, int b, int c, List<String> cur) {
        if (a > max[0]) {
            if (cur.size() > best.size()) {
                best = new ArrayList<>(cur);
            }
            return;
        }

        if (b > max[1]) {
            go(a + 1, 1, 1, cur);
            return;
        }
        if (c > max[2]) {
            go(a, b + 1, 1, cur);
            return;
        }

        count[0][a][b]++;
        count[1][a][c]++;
        count[2][b][c]++;
        if (count[0][a][b] <= k && count[1][a][c] <= k && count[2][b][c] <= k) {
            cur.add(a + " " + b + " " + c);
            go(a, b, c + 1, cur);
            cur.remove(cur.size() - 1);
        }
        count[0][a][b]--;
        count[1][a][c]--;
        count[2][b][c]--;
        go(a, b, c + 1, cur);
    }

    public void solve() {
        int j = in.nextInt(), p = in.nextInt(), s = in.nextInt();
        this.k =in.nextInt();
        max = new int[] {j, p, s};
        count = new int[3][11][11];
        best = new ArrayList<>();
        go(1, 1, 1, new ArrayList<>());

        out.println(best.size());
        for (String line : best) {
            out.println(line);
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
        new FashionSmall().run();
    }
}
