import java.util.*;
import java.io.*;

class B_as {
    Scanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int m = 0;
            int[] last = new int[n];
            int[] len = new int[n];
            for (int i = 0; i < n; i++) {
                int blen = Integer.MAX_VALUE;
                int best = -1;
                for (int j = 0; j < m; j++) {
                    if (last[j] == a[i] - 1 && len[j] < blen) {
                        best = j;
                        blen = len[j];
                    }
                }
                if (best == -1) {
                    last[m] = a[i];
                    len[m] = 1;
                    m++;
                } else {
                    last[best] = a[i];
                    len[best] = len[best] + 1;
                }
            }
            int blen = Integer.MAX_VALUE;
            for (int i = 0; i < m; i++) {
                if (len[i] < blen) {
                    blen = len[i];
                }
            }
            if (blen == Integer.MAX_VALUE) {
                blen = 0;
            }
            out.println("Case #" + test + ": " + blen);
        }
    }

    public void run() {
        try {
            in = new Scanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            solve();

            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new B_as().run();
    }
}