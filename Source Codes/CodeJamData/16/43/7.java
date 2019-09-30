package gcj.gcj2016.round2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by hama_du on 5/1/16.
 */
public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int T = in.nextInt();
        for (int t = 1 ; t <= T ; t++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int[][] pair = new int[r+c][2];
            for (int i = 0; i < r+c ; i++) {
                for (int j = 0; j < 2 ; j++) {
                    pair[i][j] = in.nextInt()-1;
                }
            }
            out.println(String.format("Case #%d:", t));
            char[][] map = solve(r, c, pair);
            if (map == null) {
                out.println("IMPOSSIBLE");
            } else {
                for (char[] line : map) {
                    out.println(String.valueOf(line));
                }
            }
        }
        out.flush();
    }

    static int[][] rw;
    static int[][] tw;

    private static char[][] solve(int r, int c, int[][] pair) {
        rw = new int[r+2][c+2];
        tw = new int[(r+c)*2][4];
        int ti = 0;
        for (int i = 1; i <= c ; i++) {
            tw[ti][0] = 0;
            tw[ti][1] = i;
            tw[ti][2] = 2;
            ti++;
        }
        for (int i = 1; i <= r ; i++) {
            tw[ti][0] = i;
            tw[ti][1] = c+1;
            tw[ti][2] = 1;
            ti++;
        }
        for (int i = c; i >= 1 ; i--) {
            tw[ti][0] = r+1;
            tw[ti][1] = i;
            tw[ti][2] = 0;
            ti++;
        }
        for (int i = r ; i >= 1 ; i--) {
            tw[ti][0] = i;
            tw[ti][1] = 0;
            tw[ti][2] = 3;
            ti++;
        }
        for (int i = 0; i < (r+c)*2 ; i++) {
            int y = tw[i][0];
            int x = tw[i][1];
            rw[y][x] = i;
        }

        int n = r*c;
        for (int p = 0 ; p < (1<<n) ; p++) {
            char[][] map = new char[r][c];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c ; j++) {
                    map[i][j] = (p & (1<<(i*c+j))) >= 1 ? '\\' : '/';
                }
            }

            boolean isOK = true;
            for (int i = 0; i < pair.length ; i++) {
                if (go(map, pair[i][0]) != pair[i][1]) {
                    isOK = false;
                    break;
                }
            }
            if (isOK) {
                return map;
            }
        }
        return null;
    }

    private static int go(char[][] map, int from) {
        int r = map.length;
        int c = map[0].length;
        int ny = tw[from][0];
        int nx = tw[from][1];
        int d = tw[from][2];

        while (true) {
            ny += DY[d];
            nx += DX[d];
            if (ny == 0 || ny == r+1 || nx == 0 || nx == c+1) {
                break;
            }
            if (map[ny-1][nx-1] == '/') {
                d = d ^ 3;
            } else {
                d = d ^ 1;
            }
        }
        return rw[ny][nx];
    }

    private static int[] DX = new int[]{0, -1, 0, 1};
    private static int[] DY = new int[]{-1, 0, 1, 0};

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}
