import java.io.*;
import java.util.*;

public class Evacuation {

    public void solve() {
        int n = in.nextInt();
        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            cnt[i] = in.nextInt();
        }

        while (true) {
            int mx = 0;
            List<Integer> all = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                if (cnt[i] > mx) {
                    mx = cnt[i];
                    all.clear();
                }
                if (cnt[i] == mx) {
                    all.add(i);
                }
            }
            if (mx == 0) {
                break;
            }

            if (all.size() % 2 == 0) {
                int c1 = all.get(0), c2 = all.get(1);
                out.print((char) ('A' + c1));
                out.print((char) ('A' + c2));
                cnt[c1]--;
                cnt[c2]--;
            } else {
                int c1 = all.get(0);
                cnt[c1]--;
                out.print((char) ('A' + c1));
            }
            out.print(' ');
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
        new Evacuation().run();
    }
}
