import java.awt.*;
import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int D = sc.nextInt();

        Point[] numPoint = new Point[H * W + 1];
        for (int i = 1; i < H + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                numPoint[sc.nextInt()] = new Point(i, j);
            }
        }

        int Q = sc.nextInt();
        int[] L = new int[Q];
        int[] R = new int[Q];
        for (int i = 0; i < Q; i++) {
            L[i] = sc.nextInt();
            R[i] = sc.nextInt();
        }

        // ??n?????????????
        long[] accum = new long[H * W + 1];
        for (int n = D + 1; n < H * W + 1; n++) {
            accum[n] = accum[n - D] + calcMagic(numPoint[n - D], numPoint[n]);
        }

        for (int i = 0; i < Q; i++) {
            out.println(accum[R[i]] - accum[L[i]]);
        }
    }

    static long calcMagic(Point xy1, Point xy2){
        return Math.abs(xy1.x - xy2.x) + Math.abs(xy1.y - xy2.y);
    }
}