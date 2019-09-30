import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B implements Runnable {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    String filename = B.class.getName().substring(0, 1);

    void preSolve() {

    }

    void solve(int testNumber) throws IOException {
        String number = next();
        int[] x = new int[number.length()];
        for (int i = 0; i < x.length; ++i) {
            x[i] = number.charAt(i) - '0';
        }

        out.print("Case #" + testNumber + ": ");

        int[] count = new int[10];
        for (int last = x.length - 1; last >= 0; --last) {
            count[x[last]]++;
            for (int i = x[last] + 1; i < 10; ++i) {
                if (count[i] > 0) {
                    --count[i];
                    x[last] = i;
                    for (int j = last + 1; j < x.length; ++j) {
                        for (int d = 0; d < 10; ++d) {
                            if (count[d] > 0) {
                                --count[d];
                                x[j] = d;
                                break;
                            }
                        }
                    }
                    for (int t : x) {
                        out.print(t);
                    }
                    out.println();
                    return;
                }
            }
        }
        count[0]++;
        x = new int[x.length + 1];
        for (int j = 0; j < x.length; ++j) {
            for (int d = j == 0 ? 1 : 0; d < 10; ++d) {
                if (count[d] > 0) {
                    --count[d];
                    x[j] = d;
                    break;
                }
            }
        }
        for (int t : x) {
            out.print(t);
        }
        out.println();
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
        new Thread(new B()).start();
    }
}