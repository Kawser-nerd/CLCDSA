import java.util.*;

public class d {

    final public static long MOD = 1000000007L;
    final public static int[] DX = {-1,0,0,1};
    final public static int[] DY = {0,-1,1,0};

    public static int[][][] sols;
    public static int index;

    public static void main(String[] args) {

        Scanner stdin = new Scanner(System.in);
        int numCases = stdin.nextInt();

        for (int loop=1; loop<=numCases; loop++) {

            int r = stdin.nextInt();
            int c = stdin.nextInt();
            sols = new int[100][r][c];
            index = 0;
            System.out.println("Case #"+loop+": "+solve(r,c));
        }
    }

    public static long solve(int r, int c) {
        int[][] grid = new int[r][c];
        long ans = solveRec(grid, 0, 0);

        int cnt = 0;
        boolean[] used = new boolean[index];
        for (int i=0; i<index; i++) {

            if (!used[i]) cnt++;
            for (int j=i+1; j<index; j++) {
                if (equal(i, j, r, c)) {
                    used[j] = true;
                }
            }
        }

        return cnt;
    }

    public static boolean equal(int i, int j, int r, int c) {

        for (int rot=0; rot<c; rot++) {

            boolean eq = true;
            for (int a=0; a<r; a++) {
                for (int b=0; b<c; b++) {
                    if (sols[i][a][b] != sols[j][a][(b+rot)%c])
                        eq = false;
                }
            }

            if (eq) return true;

        }
        return false;
    }

    public static long solveRec(int[][] grid, int x, int y) {

        int r = grid.length;
        int c = grid[0].length;

        if (!valid(grid)) return 0L;

        if (x == grid.length) {


            if (valid(grid)) {
                copy(grid, index);
                index++;
                return 1L;
            }
            return 0L;
        }

        long res = 0L;
        for (int i=1; i<=3; i++) {
            grid[x][y] = i;
            res = (res + solveRec(grid, (c*x+y+1)/c, (y+1)%c))%MOD;
            grid[x][y] = 0;
        }
        return res;
    }

    public static boolean valid(int[][] grid) {

        int r = grid.length;
        int c = grid[0].length;

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j] == 0) continue;
                else {
                    int open = 0, match = 0;

                    for (int k=0; k<DX.length; k++) {

                        int x = i + DX[k];
                        int y = (j + DY[k]+c)%c;

                        if (x < 0 || x >= r) continue;

                        int val = grid[x][y];
                        if (val == grid[i][j]) match++;
                        if (val == 0) open++;
                    }

                    if (match > grid[i][j]) return false;
                    if (match+open < grid[i][j]) return false;
                }
            }
        }

        return true;
    }

    public static void print(int[][] grid) {

        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[0].length; j++)
                System.out.print(grid[i][j]+" ");
            System.out.println();
        }
        System.out.println();
    }

    public static void copy(int[][] grid, int index) {

        for (int i=0; i<grid.length; i++)
            for (int j=0; j<grid[0].length; j++)
                sols[index][i][j] = grid[i][j];
    }
}
