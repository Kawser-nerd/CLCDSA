import java.io.IOException;
import java.io.PrintWriter;
import java.io.File;
import java.util.Scanner;

public class B implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter("B-small-attempt0.out");

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            int W = in.nextInt();
            int H = in.nextInt();
            int[] dx = new int[2];
            int[] dy = new int[2];
            for (int i = 0; i < 2; i++) {
                dx[i] = in.nextInt();
                dy[i] = in.nextInt();
            }
            int sx = in.nextInt();
            int sy = in.nextInt();
            int[] qx = new int[W * H];
            int[] qy = new int[W * H];
            int h = 0;
            int t = 1;
            qx[h] = sx;
            qy[h] = sy;
            boolean[][] u = new boolean[W][H];
            u[sx][sy] = true;
            int c = 1;
            while (h < t) {
                for (int i = 0; i < 2; i++) {
                    if (0 <= qx[h] + dx[i] && qx[h] + dx[i] < W && 0 <= qy[h] + dy[i] && qy[h] + dy[i] < H) {
                        if (!u[qx[h] + dx[i]][qy[h] + dy[i]]) {
                            u[qx[h] + dx[i]][qy[h] + dy[i]] = true;
                            qx[t] = qx[h] + dx[i];
                            qy[t] = qy[h] + dy[i];
                            t++;
                            c++;
                        }
                    }
                }
                h++;
            }
            System.out.printf("Case #%d: %d\n", test, c);
            out.printf("Case #%d: %d\n", test, c);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void main(String[] s) {
        new Thread(new B()).start();
    }
}
