import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            final int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            long[] xor = new long[32];
            for (int i = 0; i < n; i++) a[i] = in.nextInt();
            for (int i = 0; i < n; i++) b[i] = in.nextInt();

            for (int i = 0; i < 32; i++) {
                int minBin = (int) Math.pow(2, i);
                int maxBin = (int) Math.pow(2, i + 1);
                int[] ca = new int[n];
                int[] cb = new int[n];
                for (int j = 0; j < n; j++) {
                    ca[j] = a[j] % maxBin;
                    cb[j] = b[j] % maxBin;
                }
                Arrays.sort(ca);
                Arrays.sort(cb);
                for (int j = 0; j < n; j++) {
                    int cca = ca[j];
                    int lb = Search.lowerBound(cb, minBin - cca);
                    int ub = Search.upperBound(cb, maxBin - cca - 1);
                    if (cb[ub] <= maxBin - cca - 1) ub++;
                    if (cb[lb] < minBin - cca) lb++;
                    int count = ub - lb;
                    xor[i] += count;
                    lb = Search.lowerBound(cb, maxBin + minBin - cca);
                    ub = Search.upperBound(cb, maxBin + maxBin - cca - 1);
                    if (cb[ub] <= maxBin + maxBin - cca - 1) ub++;
                    if (cb[lb] < maxBin + minBin - cca) lb++;
                    count = ub - lb;
                    xor[i] += count;
                }
            }

            long ans = 0;
            for (int i = 0; i < xor.length; i++) if (xor[i] % 2 == 1) ans += Math.pow(2, i);

            out.println(ans);
        }

    }

    static class Search {
        public static int upperBound(int[] list, int lim) {
            int min = 0;
            int max = list.length - 1;
            while (true) {
                int mid = (min + max) / 2;
                if (mid == max || mid == min) break;
                if (list[mid] > lim) max = mid;
                else min = mid;
            }
            if (list[min] > lim) return min;
            else if (list[max] > lim) return max;
            else return max;
        }

        public static int lowerBound(int[] list, int lim) {
            int min = 0;
            int max = list.length - 1;
            while (true) {
                int mid = (min + max) / 2;
                if (mid == max || mid == min) break;
                if (list[mid] >= lim) max = mid;
                else min = mid;
            }
            if (list[min] >= lim) return min;
            else if (list[max] >= lim) return max;
            else return max;
        }

    }
}