import java.util.*;

public class Main {
    static int h, w, t;
    static char[][] c;
    static int[] mh4 = { 0, -1, 1, 0 };
    static int[] mw4 = { -1, 0, 0, 1 };
    static int INF = 1 << 30;


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        h = Integer.parseInt(in.next());
        w = Integer.parseInt(in.next());
        t = Integer.parseInt(in.next());
        c = new char[h][w];
        for(int i = 0; i < h; i++) c[i] = in.next().toCharArray();
        solve();
    }

    private static void solve() {
        int sh = -1, sw = -1, gh = -1, gw = -1;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(c[i][j] == 'S'){
                    sh = i;
                    sw = j;
                }else if(c[i][j] == 'G'){
                    gh = i;
                    gw = j;
                }
            }
        }

        int lo = 0, hi = t;
        while(hi - lo > 1) {
            int mid = (lo+hi)/2;
            int[][] cost = new int[h][w];
            for(int i = 0; i < h; i++) Arrays.fill(cost[i], INF);

            Queue<P> q = new ArrayDeque<>();
            q.add(new P(sw, sh));
            cost[sh][sw] = 0;

            while(!q.isEmpty()) {
                P p = q.remove();
                int pw = p.x;
                int ph = p.y;

                for(int i = 0; i < 4; i++) {
                    int tw = pw + mh4[i];
                    int th = ph + mw4[i];

                    if(tw < 0 || th < 0 || tw >= w || th >= h) {
                        continue;
                    }

                    int a = c[th][tw] == '#' ? mid : 1;
                    if(cost[th][tw] < cost[ph][pw] + a) {
                        continue;
                    }

                    q.add(new P(tw, th));
                    cost[th][tw] = cost[ph][pw] + a;
                }

            }

            if(cost[gh][gw] > t) {
                hi = mid;
            }else{
                lo = mid;
            }
        }

        System.out.println(lo);
    }

    static class P {
        int x, y;
        P(int x, int y) {
           this.x = x;
           this.y = y;
        }
    }
}