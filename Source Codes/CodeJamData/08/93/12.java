import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("C-small-attempt0.in"));
        PrintWriter out = new PrintWriter("c.out");

        int n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int[][] a = new int[r][c];
            for (int x = 0; x < r; x++) {
                for (int y = 0; y < c; y++) {
                    a[x][y] = in.nextInt();
                }
            }

            boolean[] w = new boolean[r * c];
            int max = 0;
            while (true) {
                boolean eq = true;
                int nm = 0;
                main:for (int x = 0; x < r; x++) {
                    for (int y = 0; y < c; y++) {
                        int co = 0;
                        for (int dx = -1; dx <= 1; dx++) {
                            for (int dy = -1; dy <= 1; dy++) {
                                int nx = x+dx, ny = y+dy;
                                if (0 <= nx && nx < r && 0 <= ny && ny < c && w[nx*c+ny]) {
                                    co++;
                                }
                            }
                        }
                        if (w[x*c+y] && x == r/2) nm++;
                        if (co != a[x][y]) {
                            eq = false;
                            break main;
                        }
                    }
                }

                if (eq) {
                    max = Math.max(max, nm);
                }

                int k = 0;
                while (k < w.length && w[k]) {
                    w[k] = false;
                    k++;
                }
                if (k >= w.length) break;
                w[k] = true;
            }

            out.println("Case #" + i + ": " + max);
            System.out.println(".");
        }

        in.close();
        out.close();
    }
}