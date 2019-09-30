import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] a = new char[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }
            boolean hasNotEmptyRow = false;
            for (int i = 0; i < n; i++) {
                boolean isRowEmpty = true;
                for (int j = 0; j < m; j++) {
                    if (a[i][j] != '?') {
                        isRowEmpty = false;
                    }
                }
                if (isRowEmpty) {
                    if (hasNotEmptyRow) {
                        for (int j = 0; j < m; j++) {
                            a[i][j] = a[i - 1][j];
                        }
                    }
                } else {
                    char curChar = '?';
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] != '?') {
                            if (curChar == '?') {
                                for (int j2 = 0; j2 < j; j2++) {
                                    a[i][j2] = a[i][j];
                                }
                            }
                            curChar = a[i][j];
                        }
                        a[i][j] = curChar;
                    }
                    if (!hasNotEmptyRow) {
                        for (int i2 = 0; i2 < i; i2++) {
                            for (int j = 0; j < m; j++) {
                                a[i2][j] = a[i][j];
                            }
                        }
                    }
                    hasNotEmptyRow = true;
                }

            }
            out.println();
            for (int i = 0; i < n; i++) {
                out.println(new String(a[i]));
            }
            System.err.println((t + 1) + "/" + tc + " done");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}