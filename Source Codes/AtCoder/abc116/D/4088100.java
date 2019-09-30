import java.util.*;

class Main {
    static class Sushi implements Comparable<Sushi> {
        int t;
        int d;
        boolean dup;

        Sushi(int t, int d, boolean dup) {
            this.t = t;
            this.d = d;
            this.dup = dup;
        }

        public int compareTo(Sushi other) {
            return other.d - d;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        Sushi a[] = new Sushi[N];
        for (int i = 0; i < N; i++) {
            int t = sc.nextInt();
            int d = sc.nextInt();
            a[i] = new Sushi(t, d, false);
        }
        Arrays.sort(a);
        boolean[] selected = new boolean[N + 1];
        for (int i = 0; i < N; i++) {
            if (selected[a[i].t]) {
                a[i].dup = true;
            }
            selected[a[i].t] = true;
            //System.out.printf("%d %d %b\n", a[i].t, a[i].d, a[i].dup);
        }
        long s = 0;
        long x = 0;
        selected = new boolean[N + 1];
        for (int i = 0; i < K; i++) {
            s += a[i].d;
            if (!selected[a[i].t]) {
                x += 1;
                selected[a[i].t] = true;
            }
        }
        //System.out.printf("s = %d, x = %d, %d\n", s, x, s + x*x);
        long smax = s + x * x;
        int q = K - 1; // ??????????
        while (q >= 0 && !a[q].dup) {
            q -= 1;
        }
        int p = K; // ??????????
        while (q >= 0) {
            // ??????????
            while (p < N && selected[a[p].t]) {
                p += 1;
            }
            if (p >= N) break;
            s = s - a[q].d + a[p].d;
            x += 1;
            selected[a[p].t] = true;
            if (s + x * x > smax) {
                smax = s + x * x;
            }
            // System.out.printf("s = %d, x = %d, %d\n", s, x, s + x*x);
            // ?????????
            q -= 1;
            while (q >= 0 && !a[q].dup) {
                q -= 1;
            }
        }
        System.out.printf("%d\n", smax);
    }
}