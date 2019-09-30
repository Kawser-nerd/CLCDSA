import java.util.*;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        P[] ps = new P[n];
        for (int i = 0; i < n; i++) {
            int t = sc.nextInt() - 1;
            int d = sc.nextInt();
            ps[i] = new P(t, d);
        }

        Arrays.sort(ps);

        long ans = 0;
        long cur = 0;
        boolean[] used = new boolean[n];
        LinkedList<Integer> pops = new LinkedList<>();
        long cnt = 0;

        for (int i = 0; i < k; i++) {
            ans += ps[i].d;
            cur += ps[i].d;
            if (used[ps[i].t]) {
                pops.addFirst(ps[i].d);
            } else {
                cnt++;
                used[ps[i].t] = true;
            }
        }

        ans += cnt * cnt;

        for (int i = k; i < n && !pops.isEmpty(); i++) {
            if (!used[ps[i].t]) {
                cur -= pops.removeFirst();
                cur += ps[i].d;
                cnt++;
                ans = Math.max(ans, cur + cnt * cnt);
                used[ps[i].t] = true;
            }
        }
        System.out.println(ans);
    }

    class P implements Comparable<P> {
        int t, d;
        public P(int t, int d) {
            this.t = t;
            this.d = d;
        }

        @Override
        public int compareTo(P o) {
            return o.d - d;
        }

        @Override
        public String toString() {
            return String.format("{t: %d, d: %d}", t, d);
        }
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }


    public static void main(String[] args) {
        new Main().run();
    }
}