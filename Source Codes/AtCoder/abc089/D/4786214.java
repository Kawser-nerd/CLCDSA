/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
?????????????????????????ex.-1/2=0??????>k??????????????????
???>=k???????????????
toLowerCase()???????????????????????????
ArrayDeque??pop?push?Stack????????
//import static java.lang.System.*; ??????????
???out.flush()??????????
*/
//?????Ctrl+D
import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.geom.Point2D;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        PrintWriter out = new PrintWriter(System.out);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int d = sc.nextInt();
        int[][] a = new int[h][w];
        int[] point = new int[90001];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                a[i][j] = sc.nextInt();
                point[a[i][j]] = i * w + j;
            }
        }
        long[] ds = new long[h * w + 1];
        for (int i = 1; i <= h * w; i++) {
            if (i > d) ds[i] = ds[i - d] + abs(point[i] / w - point[i - d] / w) + abs(point[i] % w - point[i - d] % w);
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            out.println(ds[r] - ds[l]);
        }
        out.close();
    }

    static class sc {
        static Scanner s = new Scanner(System.in);

        static String next() {
            return s.next();
        }

        static int nextInt() {
            return Integer.parseInt(s.next());
        }

        static long nextLong() {
            return Long.parseLong(s.next());
        }

        static double nextDouble() {
            return Double.parseDouble(s.next());
        }
    }
}