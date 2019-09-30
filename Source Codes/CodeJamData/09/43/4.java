import java.util.Scanner;
import java.util.Arrays;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C.in"));
        PrintWriter out = new PrintWriter("C.out");

        int t = in.nextInt();in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[][] p = new int[n][k];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                p[i][j] = in.nextInt();
            }
        }

        boolean[][] a = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = true;
                for (int t = 0; t < k; t++) {
                    if (p[i][t] >= p[j][t]) a[i][j] = false;
                }
            }
        }

        int[] r = new int[n];
        Arrays.fill(r, -1);
        int res = n;
        boolean[] z = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (dfs(a, r, z, i)) {
                res--;
                Arrays.fill(z, false);
            }
        }

        return "" + res;
    }

    private static boolean dfs(boolean[][] a, int[] r, boolean[] z, int i) {
        if (z[i]) return false;
        z[i] = true;
        for (int j = 0; j < a.length; j++) {
            if (a[i][j]) {
                if (r[j] == -1) {
                    r[j] = i;
                    return true;
                } else {
                    if (dfs(a, r, z, r[j])) {
                        r[j] = i;
                        return true;
                    }
                }
            }
        }

        return false;  //To change body of created methods use File | Settings | File Templates.
    }

}