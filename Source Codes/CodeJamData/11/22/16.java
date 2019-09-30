import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final String DIR = "E:\\isinev\\programming\\contests\\gcj\\11round1B\\";

    String problemName = B.class.getName();


//    String fileName = String.format(DIR + "%s-statement", problemName);
    private static final long inf = (long) 1e13;
//	String fileName = String.format(DIR + "%s-small-attempt0", problemName);
	String fileName = String.format(DIR + "%s-large", problemName);

    public void run() {
        try {
            int nt = nextInt();
            cases_loop:
            for (int it = 1; it <= nt; it++) {
                int c = nextInt();
                long d = nextInt() * 2;
                int[] cv = new int[c];
                int[] cx = new int[c];
                int n = 0;
                for (int i = 0; i < c; i++) {
                    cx[i] = nextInt() * 2;
                    cv[i] = nextInt();
                    n += cv[i];
                }
                int[] sp = new int[n];
                n = 0;
                for (int i = 0; i < c; i++) {
                    for (int j = 0; j < cv[i]; j++) {
                        sp[n++] = cx[i];
                    }
                }
                long lr = -1;
                long rr = inf;
                while (lr + 1 < rr) {
                    long xr = (lr + rr) / 2;
                    long last = -inf;
                    boolean ok;
                    check:
                    {
                        for (long p : sp) {
                            long b1 = p - xr;
                            long b2 = p + xr;
                            if (last + d > b2) {
                                ok = false;
                                break check;
                            }
                            last = Math.max(b1, last + d);
                        }
                        ok = true;
                    }
                    if (ok) {
                        rr = xr;
                    } else {
                        lr = xr;
                    }
                }
                out.format("Case #%d: %.1f%n", it, rr * .5);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    static {
        Locale.setDefault(Locale.US);
    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public B() throws FileNotFoundException {
        in = new BufferedReader(new FileReader(new File(fileName + ".in")));
        out = new PrintWriter(fileName + ".out");
        st = new StringTokenizer("");
    }

    public static void main(String[] args) throws FileNotFoundException {
        new Thread(new B()).start();
    }

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(next());
    }
}