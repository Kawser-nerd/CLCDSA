
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D1 {

    private String solveTest() throws IOException {
        int p = nextInt();
        long[] e = new long[p];
        long[] f = new long[p];
        for (int i = 0; i < p; i++) {
            e[i] = nextLong();
        }
        for (int i = 0; i < p; i++) {
            f[i] = nextLong();
        }
        long min = e[0];
        for (int i = 0; i < p; i++) {
            e[i] -= min;
        }
        long[] s = new long[60];
        int n = 0;
        long[] t = new long[p];
        int[] pr = new int[p];
        for (int i = 0; i < p; i++) {
            while (t[i] < f[i]) {
                if (i == 0 && t[i] == 0) {
                    t[i]++;
                } else {
                    s[n++] = e[i];
                    int jj = p - 1;
                    for (int j = p - 1; j >= 0; j--) if (t[j] > 0) {
                        long ee = e[j] + e[i];
                        while (e[jj] > ee) jj--;
                        t[jj] += t[j];
                        pr[jj] = j;
                    }
//                    System.out.println(e[i]);
//                    System.out.println(Arrays.toString(t));
                }
            }
        }

        for (int i = 0; i < p; i++) {
            if (e[i] == -min) {
                while (i > 0) {
                    int j = pr[i];
                    int d = i - j;
                    for (int q = 0; q < n; q++) {
                        if (s[q] == d) {
                            s[q] = -d;
                            break;
                        }
                    }
                    i = j;
                }
                break;
            }
        }
        Arrays.sort(s, 0, n);

        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i > 0) res.append(' ');
            res.append(s[i]);
        }
        return res.toString();
    }

    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new D1().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}