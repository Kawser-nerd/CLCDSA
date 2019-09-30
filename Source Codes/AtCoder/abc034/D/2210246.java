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
            int n = in.nextInt();
            int k = in.nextInt();

            int[] w = new int[n];
            int[] p = new int[n];

            for (int i = 0; i < n; i++) {
                w[i] = in.nextInt();
                p[i] = in.nextInt();
            }

            double max = 100;
            double min = 0;
            for (int i = 0; i < 200; i++) {
                double target = (max + min) / 2;
                double[] score = new double[n];
                for (int j = 0; j < n; j++) {
                    score[j] = w[j] * (((double) p[j] / 100) - (target / 100));
                }
                Arrays.sort(score);
                double sum = 0;
                for (int j = n - k; j < n; j++) {
                    sum += score[j];
                }
                if (sum > 0) min = target;
                else max = target;
            }
            out.println(min);
        }

    }
}