package round1c;


import java.util.Arrays;

public class ProbC extends Prob{

    void setup() {
        bin = true;
        bout = true;
        in = "C-small-1-attempt0.in";
        out = "cout.txt";
    }

    @Override
    public void main() {
        setup();
        reDirect();
        int T = scanner.nextInt();
        for (int cas = 1; cas <= T; cas++) {
            double ans = run();
            System.out.println(String.format("Case #%d: %f", cas, ans));
        }
    }

    double run() {
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        double u = scanner.nextDouble();
        double[] p = new double[n];
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextDouble();
        }
        Arrays.sort(p);
        double limit = -1;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || (p[i + 1] - p[i]) * (i + 1) > u) {
                limit = u / (i + 1) + p[i];
                break;
            }
            else {
                u -= (p[i + 1] - p[i]) * (i + 1);
            }
        }
        double poss = 1;
        for (int i = 0; i < n; i++) {
            if (p[i] < limit) poss *= limit;
            else poss *= p[i];
        }
        return poss;
    }

}
