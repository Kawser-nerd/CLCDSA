import java.util.*;
import static java.lang.Math.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int N = in.nextInt();
            double V = in.nextDouble();
            double X = in.nextDouble();
            Source[] S = new Source[N];
            for (int i = 0; i < N; i++) {
                S[i] = new Source(in.nextDouble(), in.nextDouble());
            }
            Arrays.sort(S);
            double[] C = new double[N];
            Arrays.fill(C, 1.0);
            int iters = 0;
            while (true) {
                iters++;
                if (iters == 20)
                    break;
                double curt = gett(C, S);
                double curv = getv(C, S);
                double curtemp = curt/curv;
                //System.out.println(curtemp+" "+X+" "+abs(curtemp-X));
                if (curv == 0 || eq(curtemp, X))
                    break;

                if (curtemp > X) {
                    for (int i = N-1; i >= 0; i--) {
                        if (C[i] == 0)
                            continue;
                        double k = (curt - X * curv) / (S[i].rate * (S[i].temp - X));
                        //System.out.println("\ta: "+k+" "+i+" "+C[i]);
                        k = min(k, C[i]);
                        if (k < 0)
                            throw new RuntimeException();
                        C[i] -= k;
                        if (eq(C[i], 0))
                            C[i] = 0;
                        break;
                    }
                } else {
                    for (int i = 0; i < N; i++) {
                        if (C[i] == 0)
                            continue;

                        double k = (curt - X * curv) / (S[i].rate * (S[i].temp - X));
                        //System.out.println("\tb: "+k+" "+i+" "+C[i]);
                        k = min(k, C[i]);
                        if (k < 0)
                            throw new RuntimeException();
                        C[i] -= k;
                        if (eq(C[i], 0))
                            C[i] = 0;
                        break;
                    }
                }
            }
            double curv = getv(C, S);
            if (curv > 0) {
                double ans = V / curv;
                System.out.format("Case #%d: %.09f\n", zz, ans);
            } else {
                System.out.format("Case #%d: IMPOSSIBLE\n", zz);
            }
        }
    }
    static double eps = 1e-9;
    static boolean eq(double a, double b) {
        return abs(a-b) < eps;
    }
    static double gett(double[] C, Source[] S) {
        double t = 0;
        for (int i = 0; i < S.length; i++)
            t += C[i] * S[i].rate * S[i].temp;
        return t;
    }
    static double getv(double[] C, Source[] S) {
        double v = 0;
        for (int i = 0; i < S.length; i++)
            v += C[i] * S[i].rate;
        return v;
    }
    static class Source implements Comparable<Source> {
        double temp, rate;
        public Source(double rate, double temp) {
            this.rate = rate;
            this.temp = temp;
        }
        public int compareTo(Source s) {
            if (temp < s.temp)
                return -1;
            if (temp > s.temp)
                return 1;
            return 0;
        }
    }
}
