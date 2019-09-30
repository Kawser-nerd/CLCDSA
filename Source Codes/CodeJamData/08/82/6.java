import java.io.IOException;
import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class BEasy implements Runnable {
    private int INF = 1000;

    class Offer {
        int c;
        int l;
        int r;

        Offer(int c, int l, int r) {
            this.c = c;
            this.l = l;
            this.r = r;
        }
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            int n = in.nextInt();

            int cn = 0;
            Map<String, Integer> cols = new HashMap<String, Integer>();
            Offer[] o = new Offer[n];
            for (int i = 0; i < n; i++) {
                String cs = in.next();
                if (!cols.containsKey(cs)) {
                    cols.put(cs, cn);
                    cn++;
                }
                int c = cols.get(cs);
                int l = in.nextInt();
                int r = in.nextInt();
                o[i] = new Offer(c, l, r);
            }
            Arrays.sort(o, new Comparator<Offer>() {
                public int compare(Offer o1, Offer o2) {
                    return o1.r - o2.r;
                }
            });

            int[] prev = new int[n];
            for (int i = 0; i < n; i++) {
                prev[i] = -1;
                 for (int j = 0; j < i - 1; j++) {
                    if (o[j].r >= o[i].l - 1) {
                        prev[i] = j;
                        if (o[j].r < o[j + 1].r) {
                            break;
                        }
                    }
                }
            }

            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < 1 << n; i++) {
                boolean ok = true;
                int last = 0;
                int uc = 0;
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        if (o[j].l > last + 1) {
                            ok = false;
                            break;
                        }
                        last = o[j].r;
                        uc |= 1 << o[j].c;
                        cnt++;
                    }
                }
                if (last < 10000) {
                    continue;
                }

                if (!ok || Integer.bitCount(uc) > 3) {
                    continue;
                }
                ans = Math.min(ans, cnt);
            }

            if (ans < INF) {
                out.printf("Case #%d: %d\n", test, ans);
            } else {
                out.printf("Case #%d: IMPOSSIBLE\n", test);
            }
        }

        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new BEasy()).start();
    }
}
