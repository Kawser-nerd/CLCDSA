import java.io.*;
import java.util.*;

public class A_as implements Runnable {

    int SZ = 6010;

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));

        int tn = in.nextInt();
        for (int test = 0; test < tn; test++) {
            int l = in.nextInt();

            int[] dx = {0, 1, 0, -1};
            int[] dy = {1, 0, -1, 0};
            int[] m = {1, 2, 1, 2};
            int d = 0;

            byte[][] a = new byte[SZ][SZ];
            int x = SZ / 2;
            int y = SZ / 2;

            for (int i = 0; i < l; i++) {
                String s = in.next();
                int t = in.nextInt();

                for (int j = 0; j < t; j++) {
                    for (int k = 0; k < s.length(); k++) {
                        switch (s.charAt(k)) {
                            case 'F':
                                a[x][y] |= m[d];
//                                System.out.println(x + " " + y + " " + m[d]);
                                x += dx[d];
                                y += dy[d];
                                break;
                            case 'L': {
                                switch (d) {
                                    case 0:
                                        x--;
                                        break;
                                    case 1:
                                        break;
                                    case 2:
                                        y++;
                                        break;
                                    case 3:
                                        x++;
                                        y--;
                                        break;
                                }
                                d = (d + 3) % 4;
                                break;
                            }
                            case 'R': {
                                switch (d) {
                                    case 0:
                                        break;
                                    case 1:
                                        y--;
                                        break;
                                    case 2:
                                        x--;
                                        y++;
                                        break;
                                    case 3:
                                        x++;
                                        break;
                                }
                                d = (d + 1) % 4;
                                break;
                            }
                        }
                    }
                }
            }

            short[][] b = new short[SZ][SZ];

            int ans = 0;
            for (int i = 0; i < SZ; i++) {
                int t = 0;
                for (int j = 1; j < SZ; j++) {
                    if ((a[i][j] & 2) != 0) {
                        b[i][j] = (short) (b[i][j - 1] + 1);
                    } else {
                        b[i][j] = b[i][j - 1];
                    }
                }
                for (int j = 0; j < SZ; j++) {
                    if (b[i][j] > 0 && b[i][j] < b[i][SZ - 1] && b[i][j] % 2 == 0) {
                        ans++;
                        b[i][j] = -1;
//                        out.println(i + " " + j);
                    }
                }
            }

            short[][] c = new short[SZ][SZ];

            for (int i = 0; i < SZ; i++) {
                int t = 0;
                for (int j = 1; j < SZ; j++) {
                    if ((a[j][i] & 1) != 0) {
                        c[i][j] = (short) (c[i][j - 1] + 1);
                    } else {
                        c[i][j] = c[i][j - 1];
                    }
                }
                for (int j = 0; j < SZ; j++) {
                    if (c[i][j] > 0 && c[i][j] < c[i][SZ - 1] && c[i][j] % 2 == 0 && b[j][i] != -1) {
                        ans++;
//                        out.println(i + " " + j);
                    }
                }
            }

            out.printf("Case #%d: %d\n", test + 1, ans);
            System.err.println("Test " + (test + 1) + " solved");
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