import java.io.*;
import java.util.*;

public class D_as_fast implements Runnable {
    int k;
    int n;
    String s;
    int best;

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("D-large.in"));
        PrintWriter out = new PrintWriter(new File("D-large.out"));

        int testn = in.nextInt();
        for (int test = 0; test < testn; test++) {
            k = in.nextInt();
            s = in.next();
            n = s.length();

            int[][] ds = new int[k][k];
            int[][] dd = new int[k][k];
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    for (int l = 0; l < n / k; l++) {
                        if (s.charAt(l * k + i) != s.charAt(l * k + j)) {
                            ds[i][j]++;
                        }
                        if (l < n / k - 1 && s.charAt(l * k + i) != s.charAt((l + 1) * k + j)) {
                            dd[i][j]++;
                        }
                    }
                }
            }

            int best = Integer.MAX_VALUE;
            int[][] a = new int[k][1 << k];
            for (int f = 0; f < k; f++) {
                for (int i = 0; i < k; i++) {
                    Arrays.fill(a[i], Integer.MAX_VALUE);
                }
                a[f][1 << f] = 0;

                for (int j = 1 << f; j < 1 << k; j++) {
                    for (int l = 0; l < k; l++) {
                        if (a[l][j] != Integer.MAX_VALUE) {
                            for (int i = 0; i < k; i++) {
                                if ((j & (1 << i)) == 0) {
                                    a[i][j | (1 << i)] = Math.min(a[i][j | (1 << i)], a[l][j] + ds[l][i]);
                                }
                            }
                        }
                    }
                }

                for (int i = 0; i < k; i++) {
                    if (a[i][(1 << k) - 1] != Integer.MAX_VALUE) {
                        int r = a[i][(1 << k) - 1] + dd[i][f];
                        if (r < best) {
                            best = r;
                        }
                    }
                }
            }
            out.printf("Case #%d: %d\n", test + 1, best + 1);
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
        new Thread(new D_as_fast()).start();
    }
}