import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;

public class B {
    Scanner in;
    PrintWriter out;

    void doit(int tnum) {
        System.err.print("Case #" + tnum + ": ");
        System.err.flush();
        int n = in.nextInt();
        long W = in.nextLong();
        long L = in.nextLong();
        long[] r = new long[n];
        for (int i = 0; i < n; ++i) r[i] = in.nextLong();
        double[] x = new double[n];
        double[] y = new double[n];
        Random random = new Random();
        int num_fails = 0;
        while (true) {
            ++num_fails;
            if (num_fails % 2 == 0) System.err.println(num_fails + " attempts failed");
            boolean failed = false;
            for (int i = 0; i < n; ++i) {
                boolean found = false;
                for (int num_try = 0; num_try < 1000; ++num_try) {
                    double X = random.nextDouble() * W;
                    double Y = random.nextDouble() * L;
                    y[i] = Y;
                    x[i] = X;
                    boolean ok = true;
                    for (int j = 0; j < i; ++j) {
                        double d1 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                        double d2 = (r[i] + r[j]) * (r[i] + r[j]);
                        if (d1 < d2 - 1e-6) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        x[i] = X;
                        y[i] = Y;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    failed = true;
                    break;
                }
            }
            if (!failed) {
                System.err.println("Ok");
                out.print("Case #" + tnum + ":");
                for (int i = 0; i < n; ++i) out.print(" " + x[i] + " " + y[i]);
                for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
                    double d1 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                    double d2 = (r[i] + r[j]) * (r[i] + r[j]);
                    System.out.println(d1 - d2);
                }
                out.println();
                return;
            }
        }

    }

    public void doit() throws IOException{
        out = new PrintWriter(new FileOutputStream("output.txt"));
        in = new Scanner(new FileInputStream("B-small-attempt1.in"));
        int T = in.nextInt();
        for (int i = 0; i < T; ++i) {
            doit(i + 1);
        }
        out.close();

    }
    public static void main(String[] args) throws IOException{
        new B().doit();
    }
}
