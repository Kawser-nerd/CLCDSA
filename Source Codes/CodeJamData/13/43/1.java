import java.io.*;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {
    FastScanner in;
    PrintWriter out;

    int[] maxInc(int[] x) {
        int[] r = new int[x.length];
        for (int i = 0; i < x.length; i++) {
            r[i] = 1;
            for (int j = 0; j < i; j++) {
                if (x[j] < x[i] && r[j] + 1 > r[i]) {
                    r[i] = r[j] + 1;
                }
            }
        }
        return r;
    }

    int[] maxDec(int[] x) {
        int[] r = new int[x.length];
        for (int i = x.length - 1; i >= 0; i--) {
            r[i] = 1;
            for (int j = i + 1; j < x.length; j++) {
                if (x[j] < x[i] && r[j] + 1 > r[i]) {
                    r[i] = r[j] + 1;
                }
            }
        }
        return r;
    }

    int[] solve(int[] a, int[] b) {
        int n = a.length;
        int[] x = new int[n];

        search:
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[j] == 0) {
                    boolean fail = false;
                    int A = 1;
                    for (int k = 0; k < j; k++) {
                        if (x[k] != 0 && a[k] + 1 > A) {
                            A = a[k] + 1;
                        }
                        if (x[k] == 0 && b[k] <= b[j]) {
                            fail = true;
                        }
                    }
                    int B = 1;
                    for (int k = j + 1; k < n; k++) {
                        if (x[k] != 0 && b[k] + 1 > B) {
                            B = b[k] + 1;
                        }
                        if (x[k] == 0 && a[k] <= a[j]) {
                            fail = true;
                        }
                    }
                    if (A == a[j] && B == b[j] && !fail) {
                        x[j] = i;
                        continue search;
                    }
                }
            }
            throw new AssertionError();
        }

        int[] A = maxInc(x);
        int[] B = maxDec(x);
        if (!Arrays.equals(a, A)) {
            System.out.println(Arrays.toString(x));
            System.out.println(Arrays.toString(a));
            System.out.println(Arrays.toString(A));
            System.out.println(Arrays.toString(b));
            System.out.println(Arrays.toString(B));
            throw new AssertionError();
        }
        if (!Arrays.equals(b, B)) {
            System.out.println(Arrays.toString(x));
            System.out.println(Arrays.toString(a));
            System.out.println(Arrays.toString(A));
            System.out.println(Arrays.toString(b));
            System.out.println(Arrays.toString(B));
            throw new AssertionError();
        }

        return x;
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);
            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 0; i < n; i++) {
                b[i] = in.nextInt();
            }

            int[] x = solve(a, b);

            out("Case #%d:", test);
            for (int i = 0; i < n; i++) {
                out(" %d", x[i]);
            }
            out("\n");
        }
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }

    Random rnd = new Random(239042403820482048L);

    int[] randPerm(int n) {
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            int j = rnd.nextInt(i + 1);
            r[i] = r[j];
            r[j] = i;
        }
        return r;
    }

    void stress() {
        int z = 0;
        while (true) {
            z++;
            int[] r = randPerm(2000);
            long time = System.currentTimeMillis();
            solve(maxInc(r), maxDec(r));
            System.out.println(System.currentTimeMillis() - time);
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}