import java.io.*;
import java.util.*;

public class Go {

    public void solve() {
        int n = in.nextInt(), l = in.nextInt();
        Set<String> good = new HashSet<>();
        for (int i = 0; i < n; i++) {
            good.add(in.nextToken());
        }
        String bad = in.nextToken();
        if (good.contains(bad)) {
            out.println("IMPOSSIBLE");
            return;
        }
        if (l == 1) {
            out.println("? 0");
            return;
        }
        for (int i = 0; i < l + 1; i++) {
            out.print(1 - (i % 2));
        }
        out.print("0?");
        for (int i = 0; i < l + 1; i++) {
            out.print(1 - (i % 2));
        }
        out.print(' ');
        for (int i = 0; i < l - 1; i++) {
            out.print('?');
        }
        out.println();
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
        new Go().run();
    }
}
