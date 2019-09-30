import java.io.*;
import java.util.*;
 
public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;
 
    private void solve(Scanner sc, PrintWriter out) {
        int N = sc.nextInt();
        int[] p = new int[N];
        for (int i = 0; i < N; ++i) {
            p[i] = sc.nextInt() - 1;
        }
 
        int[] r = new int[N];
        for (int i = 0; i < N; ++i) {
            r[p[i]] = i + 1;
        }
        int[] a = new int[N];
        int[] b = new int[N];
        for (int i = 0; i < N; ++i) {
            a[i] = N * (i + 1);
            b[i] = N * (N - i - 1) + r[i];
        }
//      for (int i = 0; i < N - 1; ++i) {
//          while (a[p[i]] + b[p[i]] >= a[p[i + 1]] + b[p[i + 1]]) {
//              for (int j = p[i + 1]; j < N; ++j) {
//                  ++a[j];
//              }
//              for (int j = p[i + 1]; j >= 0; --j) {
//                  ++b[j];
//              }
//          }
//      }
        for (int i = 0; i < N; ++i) {
            if (i > 0) {
                out.print(" ");
            }
            out.print(a[i]);
        }
        out.println();
        for (int i = 0; i < N; ++i) {
            if (i > 0) {
                out.print(" ");
            }
            out.print(b[i]);
        }
        out.println();
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();
 
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Main().solve(sc, out);
        out.flush();
 
        long G = System.currentTimeMillis();
        if (elapsed) {
            System.err.println((G - S) + "ms");
        }
    }
}