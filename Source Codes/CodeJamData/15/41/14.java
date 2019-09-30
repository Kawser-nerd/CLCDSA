import java.util.*;
import static java.lang.Math.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
nextcase:
        for (int zz = 1; zz <= T; zz++) {
            int R = in.nextInt();
            int C = in.nextInt();
            int[][] G = new int[R][C];
            for (int i = 0; i < R; i++) {
                String S = in.next();
                for (int j = 0; j < C; j++) {
                    char c = S.charAt(j);
                    if (c == '.')
                        G[i][j] = EMPTY;
                    else if (c == '<')
                        G[i][j] = LEFT;
                    else if (c == '>')
                        G[i][j] = RIGHT;
                    else if (c == 'v')
                        G[i][j] = DOWN;
                    else if (c == '^')
                        G[i][j] = UP;
                }
            }
            int ans = 0;
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (G[r][c] == EMPTY)
                        continue;
                    boolean[] ok = new boolean[4];
                    boolean any = false;
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        ok[d] = false;
                        while (0 <= nr && nr < R && 0 <= nc && nc < C) {
                            if (G[nr][nc] != EMPTY) {
                                ok[d] = true;
                                any = true;
                                break;
                            }
                            nr += dr[d];
                            nc += dc[d];
                        }
                    }
                    if (!any) {
                        System.out.format("Case #%d: IMPOSSIBLE\n", zz);
                        continue nextcase;
                    }
                    if (!ok[G[r][c]-1]) {
                        ans++;
                    }
                }
            }
            System.out.format("Case #%d: %d\n", zz, ans);
        }
    }
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, -1, 0, 1};
    static int EMPTY = 0;
    static int UP = 1;
    static int LEFT = 2;
    static int DOWN = 3;
    static int RIGHT = 4;
}
