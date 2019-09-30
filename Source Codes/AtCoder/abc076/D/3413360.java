import java.util.Scanner;
 
public class Main {
 
    public static void main(String[] args) {
        new Main().compute();
    }
 
    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] t = new int[N + 1];
        int[] v = new int[N + 1];
        for (int i = 0; i < N; i++) {
            t[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            v[i] = sc.nextInt();
        }
        for (int i = N - 1; i >= 0; i--) {
            v[i] = Math.min(v[i], v[i + 1] + t[i]);
        }
        double x = 0;
        double vc = 0;
        for (int i = 0; i < N; i++) {
            double vn = v[i + 1];
            if (v[i] < vn) {
                vn = v[i];
            }
            if (vc + t[i] < vn) {
                double vmax = vc + t[i];
                x += vmax * t[i];
                x -= (vmax - vc) * (vmax - vc) / 2;
                vc = vc + t[i];
            } else {
                double vmax = Math.min(v[i], (vc + vn + t[i]) / 2);
                x += vmax * t[i];
                x -= ((vmax - vc) * (vmax - vc) + (vmax - vn) * (vmax - vn)) / 2;
                vc = vn;
            }
        }
        System.out.println(x);
    }
}