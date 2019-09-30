import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    int[] primes;

    {
        boolean[] ip = new boolean[1000009];
        int cnt = 0;
        for (int i = 2; i < ip.length; ++i) {
            if (!ip[i]) {
                ++cnt;
                for (int j = 2 * i; j < ip.length; j += i) {
                    ip[j] = true;
                }
            }
        }
        primes = new int[cnt];
        for (int i = 2, j = 0; i < ip.length; ++i) {
            if (!ip[i]) {
                primes[j++] = i;
            }
        }
    }

    public void solveOne(String prefix) throws IOException {
        long n = nextLong();
        int ans = 0;
        for (int p : primes) {
            if (n / p < p) {
                break;
            }
            long pp = 1;
            int cnt = 0;
            while (n / pp >= p) {
                pp *= p;
                ++cnt;
            }
            ans += cnt - 1;
//            System.err.println(n + "|" + p + ": " + cnt);
        }
        if (n > 1) {
            ++ans;
        }
        out.println(prefix + ans);
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(C.class.getSimpleName() + ".in"));
        out = new PrintWriter(C.class.getSimpleName() + ".out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d: ", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
