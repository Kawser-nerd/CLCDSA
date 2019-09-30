package round3;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round3/A-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round3/A-small-0.in"), new FileOutputStream("round3/A-small-0.out"));
        io = new Kattio(new FileInputStream("round3/A-large-0.in"), new FileOutputStream("round3/A-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new A().solve(io);
        }
        io.close();
    }

    long a[], sum[];
    double best;

    private void check(int left, int right) {
        if (left > right) return;
        if (left < 0) return;
        long ival1 = sum[left];
        long ival2 = sum[right+1] - ival1;
        long ival3 = sum[sum.length - 1] - sum[right + 1];
        if (ival1+ival2+ival3!=sum[sum.length-1]) throw new RuntimeException();

        long sig = Math.max(ival1, Math.max(ival2, ival3));
        double arnar = sum[sum.length - 1] - sig;
        best = Math.max(best, arnar / (arnar + sig));
    }

    private void solve(Kattio io) {
        int N = io.getInt(), p = io.getInt(), q = io.getInt(), r = io.getInt(), s = io.getInt();
        a = new long[N];
        sum = new long[N + 1];
        for (int i = 0; i < N; i++) {
            a[i] = (((i * (long) p) + q) % r + s);
            sum[i+1] = sum[i] + a[i];
        }
        best = 0.0;
        for (int i = 0; i < N; i++) {
            long right = sum[N] - sum[i+1];

            int lo = 0, hi = N;
            while (lo < hi) {
                int j = (lo+hi)/2;
                if (sum[j] < right) lo = j + 1; else hi = j;
            }
            check(lo-2, i);
            check(lo-1, i);
            check(lo, i);
            check(lo+1, i);
            check(lo+2, i);
        }
        io.println(best);
    }
}
