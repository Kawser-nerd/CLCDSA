package gcj2015.r1;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class LoggingLarge {

    static PrintWriter out;

    public static void main(String[] args) throws Exception {
        String name = "gcj2015/r1/C-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        ExecutorService service = Executors.newFixedThreadPool(count);
        List<Future<int[]>> futures = new ArrayList<>();
        for (int cc = 1; cc <= count; cc++) {
            int n = s.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            for(int i=0; i<n; i++) {
                x[i] = s.nextInt();
                y[i] = s.nextInt();
            }
            futures.add(service.submit(new Solver(n, x, y)));
        }
        for (int cc = 1; cc <= count; cc++) {
            out.print("Case #" + cc + ": ");
            out.println();
            int[] res = futures.get(cc-1).get();
            for(int r : res) {
                out.println(r);
            }
        }
        service.shutdown();
        out.close();
    }

    static class Solver implements Callable<int[]> {

        int n;
        int[] x;
        int[] y;

        public Solver(int n, int[] x, int[] y) {
            this.n = n;
            this.x = x;
            this.y  = y;
        }

        public int[] call() {
            int[] res = new int[n];
            if (n <= 3) {
                return res;
            }
            Arrays.fill(res, n - 3);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int u = 0;
                    int d = 0;
                    long base = (long) (y[j] - y[i]) * x[i] - (long) (x[j] - x[i]) * y[i];
                    for (int k = 0; k < n; k++) {
                        long a = (long) (y[j] - y[i]) * x[k] - (long) (x[j] - x[i]) * y[k];
                        if (a > base) {
                            u++;
                        } else if (a < base) {
                            d++;
                        }
                    }
                    res[i] = Math.min(res[i], u);
                    res[i] = Math.min(res[i], d);
                    res[j] = Math.min(res[j], u);
                    res[j] = Math.min(res[j], d);
                }
            }
            return res;
        }
    }

}
