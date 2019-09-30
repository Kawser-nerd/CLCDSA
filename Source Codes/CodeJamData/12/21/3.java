
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
import java.text.DecimalFormat;

public class A implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new A(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter(System.out);
            out = new PrintWriter(new FileWriter("src/output.txt"));
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String nextString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    boolean notLast(int[] a, int id, double percentage, int sum) {
        double value = a[id] + sum * percentage;
        double leftSum = sum * (1 - percentage);
        int[] b = Arrays.copyOf(a, a.length);
        b[id] = 0;
        Arrays.sort(b);
        for (int i = 1; i < b.length; i++) {
            if (b[i] > value) {
                break;
            } else {
                leftSum -= (value - b[i]);
            }
        }
        if (leftSum < 0)
            return true;
        else
            return false;
    }

    void solve() throws IOException {
        DecimalFormat format = new DecimalFormat("#.########");
        int testcases = nextInt();
        for (int t = 1; t <= testcases; t++) {
            out.print("Case #" + t + ": ");
            int n = nextInt();
            int[] score = new int[n];
            for (int i = 0; i < n; i++) {
                score[i] = nextInt();
            }

            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += score[i];
            }

            for (int i = 0; i < n; i++) {
                double l = 0, r = 1;
                for (int q = 0; q < 100; q++) {
                    double m = (l + r) / 2;
                    if (notLast(score, i, m, sum)) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                out.print(format.format(l * 100) + " ");
            }
            out.println();
        }
    }
}