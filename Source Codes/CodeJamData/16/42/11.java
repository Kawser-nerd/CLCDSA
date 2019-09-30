package round2;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Arrays;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round2/B-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round2/B-small-attempt0.in"), new FileOutputStream("round2/B-small-0.out"));
        io = new Kattio(new FileInputStream("round2/B-large.in"), new FileOutputStream("round2/B-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new B().solve(io);
        }
        io.close();
    }

    private double evenProb(double[] p) {
        int k = p.length/2;
        double[] yes = new double[k+1];
        yes[0] = 1.0;
        for (int i = 0; i < p.length; i++) {
            double[] oldyes = yes;
            yes = new double[k+1];
            for (int j = 0; j <= k; j++) {
                yes[j] = oldyes[j] * (1-p[i]) + (j > 0 ? oldyes[j-1]*p[i] : 0);
            }
        }
        return yes[k];
    }

    private void solve(Kattio io) {
        int N = io.getInt(), K = io.getInt();
        double max = 0.0;
        double p[] = new double[N];
        double best[] = null;
        for (int i = 0; i < N; i++) {
            p[i] = io.getDouble();
        }
        Arrays.sort(p);

        /*
        for (int mask = 0; mask < (1 << N); mask++) {
            double pselected[] = new double[K];
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (((1<<i)&mask)>0) {
                    if (cnt < K) {
                        pselected[cnt] = p[i];
                    }
                    cnt++;
                }
            }
            if (cnt == K) {
                double v = evenProb(pselected);
                if (v > max) {
                    max = v;
                    best = pselected.clone();
                }
            }
        }
        */
        for (int left = 0; left <= K; left++) {
            double pselected[] = new double[K];
            for (int i = 0; i < left; i++) {
                pselected[i] = p[i];
            }
            for (int i = 0; i < K - left; i++) {
                pselected[left+i] = p[N-i-1];
            }
            double v = evenProb(pselected);
            if (v > max) {
                max = v;
                best = pselected.clone();
            }
        }
        io.println(String.format("%.10f", max));
//        for (int i = 0; i < K; i++) io.print(best[i] + " "); io.println();

    }
}
