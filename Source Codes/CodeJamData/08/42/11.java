import java.io.*;
import java.util.*;

public class B_as implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));

        int testn = in.nextInt();
        for (int test = 0; test < testn; test++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int a = in.nextInt();

            boolean found = false;
            search:
            for (int x1 = -n; x1 <= n; x1++) {
                for (int y1 = -m; y1 <= m; y1++) {
                    for (int x2 = -n; x2 <= n; x2++) {
                        int y2 = 1;
                        if (x1 == 0) {
                            if (a + x2 * y1 != 0) {
                                continue;
                            }
                        } else {
                            y2 = (a + x2 * y1) / x1;
                        }
                        if (x1 * y2 - x2 * y1 == a) {
                            int sx = Math.min(0, Math.min(x1, x2));
                            int sy = Math.min(0, Math.min(y1, y2));
                            int tx1 = x1 - sx;
                            int tx2 = x2 - sx;
                            int tx3 = 0 - sx;
                            int ty1 = y1 - sy;
                            int ty2 = y2 - sy;
                            int ty3 = 0 - sy;
                            if (tx1 <= n && tx2 <= n && tx3 <= n && ty1 <= m && ty2 <= m && ty3 <= m) {
                                out.printf("Case #%d: %d %d %d %d %d %d\n", test + 1, tx1, ty1, tx2, ty2, tx3, ty3);
                                found = true;
                                break search;
                            }
                        }
                    }
                }
            }

            if (!found) {
                out.printf("Case #%d: IMPOSSIBLE\n", test + 1);
            }
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
        new Thread(new B_as()).start();
    }
}