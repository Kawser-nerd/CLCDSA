import java.util.*;

public class Main {
    private class Section {
        int l, r, v;

        public Section(int now, int t, int v) {
            this.l = now;
            this.r = now + t;
            this.v = v;
        }

        public double getMaxV(double t) {
            if (t < l) {
                return v + (l - t);
            } else if (r < t) {
                return v + (t - r);
            } else {
                return v;
            }
        }
    }

    public void main(Scanner sc) {
        int n = sc.nextInt();
        int t[] = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = sc.nextInt();
        }

        Section secs[] = new Section[n + 2];
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int v = sc.nextInt();
            secs[i] = new Section(sum, t[i - 1], v);
            sum += t[i - 1];
        }

        secs[0] = new Section(0, 0, 0);
        secs[n + 1] = new Section(sum, 0, 0);

        double ans = 0.0;
        for (double now = 0.0; now <= sum - 0.5; now += 0.5) {
            double v1 = secs[0].getMaxV(now);
            double v2 = secs[0].getMaxV(now + 0.5);
            for (int i = 1; i < n + 2; i++) {
                v1 = Math.min(v1, secs[i].getMaxV(now));
                v2 = Math.min(v2, secs[i].getMaxV(now + 0.5));
            }

            ans += (v1 + v2) * 0.25;
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}