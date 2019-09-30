import java.io.*;
import java.util.*;

public class C_as implements Runnable {
    int[] v;
    int[] cnt;

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("C-large.in"));
        PrintWriter out = new PrintWriter(new File("C-large.out"));

        int tn = in.nextInt();
        for (int test = 0; test < tn; test++) {
            int K = in.nextInt();
            int n = in.nextInt();
            int[] d = new int[n];
            for (int i = 0; i < n; i++) {
                d[i] = in.nextInt() - 1;
            }

            v = new int[K];
            int s = 1;
            while (s < K) {
                s = 2 * s;
            }
            cnt = new int[2 * s];
            for (int i = s; i < s + K; i++) {
                cnt[i] = 1;
            }
            for (int i = s - 1; i >= 1; i--) {
                cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
            }

            Arrays.fill(v, -1);
            int before = 0;
            for (int i = 0; i < K; i++) {
                int go = (i + 1) % (K - i);
                int wh = (before + go) % (K - i);
                if (wh == 0) {
                    wh = K - i;
                }
                before = wh - 1;

                int nd = 1;
                while (nd < s) {
                    if (cnt[2 * nd] >= wh) {
                        nd = 2 * nd;
                    } else {
                        wh -= cnt[2 * nd];
                        nd = 2 * nd + 1;
                    }
                }
                v[nd - s] = i;
                cnt[nd] = 0;
                while (nd > 1) {
                    nd /= 2;
                    cnt[nd] = cnt[2 * nd] + cnt[2 * nd + 1];
                }
            }

            out.print("Case #" + (test + 1) + ":");
            for (int i = 0; i < n; i++) {
                out.print(" " + (v[d[i]] + 1));
            }
            out.println();
        }

        in.close();
        out.close();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] s) {
        Locale.setDefault(Locale.US);
        new Thread(new C_as()).start();
    }
}