import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class A implements Runnable {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    String filename = A.class.getName().substring(0, 1);

    void preSolve() {

    }

    void solve(int testNumber) throws IOException {
        int n = nextInt();
        String[] data = new String[n];
        for (int i = 0; i < n; ++i) {
            data[i] = next();
        }
        int[] minRow = new int[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (data[i].charAt(j) == '1') {
                    minRow[i] = j;
                }
            }
        }

        int ans = 0;

        for (int row = 0; row < n; ++row) {
            for (int t = row; t < n; ++t) {
                if (minRow[t] <= row) {
                    for (int i = t; i > row; --i) {
                        int tmp = minRow[i];
                        minRow[i] = minRow[i - 1];
                        minRow[i - 1] = tmp;
                        ++ans;
                    }
                    break;
                }
            }
        }

        out.println("Case #" + testNumber + ": " + ans);
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(filename + ".out");
            eat(null);

            preSolve();
            int nt = nextInt();
            for (int i = 1; i <= nt; ++i) {
                long t0 = System.currentTimeMillis();
                solve(i);
                t0 = System.currentTimeMillis() - t0;
                System.out.println(i + "/" + nt + " done in " + t0 + " ms.");
            }

            out.close();
            in.close();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    void eat(String s) {
        st = s == null ? null : new StringTokenizer(s);
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextIntArray() throws IOException {
        int n = nextInt();
        int[] rv = new int[n];
        for (int i = 0; i < n; ++i) {
            rv[i] = nextInt();
        }
        return rv;
    }

    int[] nextIntArrayFromLine() throws IOException {
        StringTokenizer st = new StringTokenizer(nextLine());
        int[] rv = new int[st.countTokens()];
        for (int i = 0; i < rv.length; ++i) {
            rv[i] = Integer.parseInt(st.nextToken());
        }
        return rv;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String nextLine() throws IOException {
        eat(null);
        return in.readLine();
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new A()).start();
    }
}