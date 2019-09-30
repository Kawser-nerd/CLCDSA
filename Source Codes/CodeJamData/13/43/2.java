
import sun.reflect.generics.tree.ArrayTypeSignature;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            y[i] = in.nextInt();
        }
        boolean[][] a = new boolean[n][n];
        boolean[][] b1 = new boolean[n][n];
        boolean[][] b2 = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = (i > j && x[i] <= x[j]) || (i < j && y[i] <= y[j]);
                b1[i][j] = (i < j && x[j] ==  x[i] + 1);
                b2[i][j] =  (i > j && y[j] == y[i] + 1);
            }
        }
        int[] d = new int[n];
        int[] d1 = new int[n];
        int[] d2 = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j]) d[j]++;
                if (b1[i][j]) d1[j]++;
                if (b2[i][j]) d2[j]++;
            }
        }
        int[] res = new int[n];
        boolean[] z = new boolean[n];
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (z[j] || d[j] > 0 || d1[j] > 0|| d2[j] > 0) {
                j++;
            }
//            System.out.println(j);
            z[j] = true;
            for (int k = 0; k < n; k++) {
                if (a[j][k]) d[k]--;
                if (b1[j][k]) d1[k] = 0;
                if (b2[j][k]) d2[k] = 0;
            }
            res[j] = i;
        }
        int[] xx = new int[n];
        int[] yy = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) if (res[j] < res[i]) {
                xx[i] = Math.max(xx[j], xx[i]);
            }
            xx[i]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) if (res[j] < res[i]) {
                yy[i] = Math.max(yy[j], yy[i]);
            }
            yy[i]++;
        }
        for (int i = 0; i < n; i++) {
            if (x[i] != xx[i] || y[i] != yy[i]) {
                System.out.println(Arrays.toString(x));
                System.out.println(Arrays.toString(xx));
                System.out.println(Arrays.toString(y));
                System.out.println(Arrays.toString(yy));
                System.out.println(Arrays.toString(res));
                break;
            }
        }

        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < n; i++) {
            sb.append(res[i] + 1).append(" ");
        }
        return sb.toString();
    }
}