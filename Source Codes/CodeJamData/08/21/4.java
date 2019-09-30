import java.io.*;
import java.util.*;

public class A_as implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));

        int tn = in.nextInt();
        for (int test = 0; test < tn; test++) {
            int n = in.nextInt();
            long A = in.nextLong();
            long B = in.nextLong();
            long C = in.nextLong();
            long D = in.nextLong();

            long[] x = new long[n];
            long[] y = new long[n];
            x[0] = in.nextLong();
            y[0] = in.nextLong();

            long M = in.nextLong();

            for (int i = 1; i < n; i++) {
                x[i] = (A * x[i - 1] + B) % M;
                y[i] = (C * y[i - 1] + D) % M;
            }

            long[][] cnt = new long[3][3];

            for (int i = 0; i < n; i++) {
                cnt[(int) (x[i] % 3)][(int) (y[i] % 3)]++;
            }

            long ans = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ans += (cnt[i][j]) * (cnt[i][j] - 1) * (cnt[i][j] - 2);
                }
            }

            for (int x1 = 0; x1 < 3; x1++) {
                for (int x2 = 0; x2 < 3; x2++) {
                    for (int x3 = 0; x3 < 3; x3++) {
                        for (int y1 = 0; y1 < 3; y1++) {
                            for (int y2 = 0; y2 < 3; y2++) {
                                for (int y3 = 0; y3 < 3; y3++) {
                                    if ((x1 != x2 || y1 != y2) && (x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
//                                        System.out.println(x1 + " " + y1 + "  " + x2 + " " + y2 + "  " + x3 + " " + y3 + "  " + cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3]);
                                        ans += cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3] ;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            System.out.println(ans % 6);
            ans /= 6;

            out.printf("Case #%d: %d\n", test + 1, ans);
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
        new Thread(new A_as()).start();
    }
}