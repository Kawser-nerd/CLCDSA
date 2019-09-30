/**
 * Created by hiroshi on 2016/03/23.
 */
import java.util.*;
import java.util.concurrent.SynchronousQueue;

public class Main {
    public static double f (int[] x, int[] c, double p) {
        double max = 0;
        int N = x.length;
        for (int i = 0; i < N; i++) {
            max = Math.max(max, Math.abs(p-x[i])*c[i]);
        }
        return max;
    }
    public static double search (int[] x, int[] c) {
        double l = -100001, r = 100001;
        int L = 100;
        while (L-- >= 0) {
            double ll = (l*2+r)/3;
            double rr = (l+r*2)/3;
            if (f(x, c, ll) > f(x, c, rr)) l = ll;
            else r = rr;
        }
        return l;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        int[] c = new int[N];
        for (int i = 0; i < N; i++) {
             x[i] = sc.nextInt();
             y[i] = sc.nextInt();
             c[i] = sc.nextInt();
        }
        double lx = search(x, c);
        double ly = search(y, c);
        double ans = Math.max(f(x, c, lx), f(y, c, ly));
        System.out.println(ans);
    }
}