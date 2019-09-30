import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

public class C {

    static String[] answers;
    static AtomicInteger ready;

    static class Attack {
        int w, e;
        int s;
        int d;

        Attack(int w, int e, int s, int d) {
            this.w = w;
            this.e = e;
            this.s = s;
            this.d = d;
        }

        @Override
        public String toString() {
            return "[" + w + "; " + e + ")x" + s;
        }
    }

    static class Tribe {
        int d;
        int n;
        int w, e;
        int s;
        int dd;
        int dp;
        int ds;

        Tribe(int d, int n, int w, int e, int s, int dd, int dp, int ds) {
            this.d = d;
            this.n = n;
            this.w = w;
            this.e = e;
            this.s = s;
            this.dd = dd;
            this.dp = dp;
            this.ds = ds;
        }

        Attack attack(int i) {
             return new Attack(w + dp * i, e + dp * i, s + ds * i, d + dd * i);
        }
    }

    static class Wall {
        int[] h;
        int leftmost;

        Wall(int leftmost, int rightmost) {
            this.leftmost = leftmost;
            h = new int[rightmost - leftmost];
        }

        private int get(int i) {
            return h[i - leftmost];
        }

        private void set(int i, int v) {
            h[i - leftmost] = v;
        }

        boolean succeded(Attack a) {
            for (int i = a.w; i < a.e; i++) {
                if (get(i) < a.s) {
                    return true;
                }
            }
            return false;
        }

        void raise(Attack a) {
            for (int i = a.w; i < a.e; i++) {
                set(i, Math.max(a.s, get(i)));
            }
        }
    }

    static class Solver implements Runnable {

        int id;
        Tribe[] tr;
        String result;

        Solver(Tribe[] t, int id) {
            this.tr = t;
            this.id = id;
        }

        @Override
        public void run() {
            int minAttacked = tr[0].w;
            int maxAttacked = tr[0].e;
            for (Tribe t : tr) {
                minAttacked = Math.min(minAttacked, t.w + (t.n - 1) * t.dp);
                minAttacked = Math.min(minAttacked, t.w);
                maxAttacked = Math.max(maxAttacked, t.e + (t.n - 1) * t.dp);
                maxAttacked = Math.max(maxAttacked, t.e);
            }
            Wall w = new Wall(minAttacked, maxAttacked);

            TreeMap<Integer, List<Attack>> e = new TreeMap<Integer, List<Attack>>();
            for (Tribe t : tr) {
                for (int i = 0; i < t.n; i++) {
                    Attack a = t.attack(i);
                    if (!e.containsKey(a.d)) {
                        e.put(a.d, new ArrayList<Attack>());
                    }
                    e.get(a.d).add(a);
                }
            }

            int ans = 0;
            for (List<Attack> attacks : e.values()) {
                for (Attack a : attacks) {
                    ans += w.succeded(a) ? 1 : 0;
                }
                for (Attack a : attacks) {
                    w.raise(a);
                }
            }

            result = "" + ans;
            answers[id] = result;
            ready.incrementAndGet();
            System.err.println(id + " ready " + result);
        }
    }

    void run() throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output_" + System.currentTimeMillis() + ".txt");
        ready = new AtomicInteger(0);
        int tests = in.nextInt();
        answers = new String[tests];
        Executor e = Executors.newFixedThreadPool(tests);
        for (int i = 0; i < tests; i++) {
            int tribes = in.nextInt();
            Tribe[] t = new Tribe[tribes];
            for (int j = 0; j < tribes; j++) {
                t[j] = new Tribe(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
            }
            Solver s = new Solver(t, i);
            e.execute(s);
        }
        while (ready.get() < tests)
            ;
        for (int i = 0; i < tests; i++) {
            out.println("Case #" + (i+1) + ": " + answers[i]);
        }
        out.close();
        System.exit(0);
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().run();
    }

    static Scanner in;
    static PrintWriter out;
}
