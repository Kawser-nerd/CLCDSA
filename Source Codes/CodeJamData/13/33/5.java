import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class C {
    public static final char TASK = 'c';
    public static final boolean IS_SOUT = false;
//    public static final String FILE_MASK = "%-small-attempt0";
    public static final String FILE_MASK = "%-large";

    public void runOnce(Scanner input, PrintWriter output) {
        List<Attack> attacks = new ArrayList<Attack>();

        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            int di = input.nextInt();
            int ni = input.nextInt();
            int wi = input.nextInt();
            int ei = input.nextInt();
            int si = input.nextInt();
            int deltaDi = input.nextInt();
            int deltaPi = input.nextInt();
            int deltaSi = input.nextInt();

            for (int j = 0; j < ni; j++) {
                attacks.add(new Attack(wi, ei, si, di));
                wi += deltaPi;
                ei += deltaPi;
                si += deltaSi;
                di += deltaDi;
            }
        }

        Collections.sort(attacks);

        int ans = 0;

        Wall wall = new Wall(-200 * 1000 * 1000, 200 * 1000 * 1000); // :-)

        List<Attack> toIncrease = new ArrayList<Attack>();
        int lastDay = -1;
        for (Attack attack : attacks) {
            if (attack.d != lastDay) {
                for (Attack a : toIncrease) {
                    wall.increase(a.l, a.r, a.s);
                }
                toIncrease.clear();
                lastDay = attack.d;
            }
            if (wall.getMin(attack.l, attack.r) < attack.s) {
                ans++;
            }
            toIncrease.add(attack);
        }

        output.println(ans);
    }

    public void run(Scanner input, PrintWriter output) {
        int t = input.nextInt();

        input.nextLine();
        for (int tt = 1; tt <= t; tt++) {
            output.print("Case #" + tt + ": ");
            runOnce(input, output);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner input;
        PrintWriter output;

        if (IS_SOUT) {
            input = new Scanner(System.in);
            output = new PrintWriter(System.out);
        } else {
            input = new Scanner(new File(FILE_MASK.replace('%', TASK) + ".in"));
            output = new PrintWriter(new File(FILE_MASK.replace('%', TASK) + ".out"));
        }

        new C().run(input, output);

        input.close();
        output.close();

//        Wall w = new Wall(-10, 10);
//        w.increase(0, 3, 3);
//        w.increase(0, 5, 1);
//        w.increase(0, 1, 5);
//        System.out.println(w.getMin(0, 2));
    }

    public static class Attack implements Comparable<Attack> {
        public final int l;
        public final int r;
        public final int s;
        public final int d;

        public Attack(int l, int r, int s, int d) {
            this.l = l;
            this.r = r;
            this.s = s;
            this.d = d;
        }

        @Override
        public int compareTo(Attack attack) {
            return d - attack.d;
        }

        @Override
        public String toString() {
            return "Attack{" +
                    "l=" + l +
                    ", r=" + r +
                    ", s=" + s +
                    ", d=" + d +
                    '}';
        }
    }

    public static class Wall {
        private final Node root;

        public Wall(int l, int r) {
            root = new Node(l, r);
        }

        // l,r <= 10^8

        // r not included
        public void increase(int l, int r, int s) {
            root.increase(l, r, s);
        }

        // r not included
        public int getMin(int l, int r) {
            return root.getMin(l, r);
        }
    }

//    public static class Wall {
//        private int[] wall = new int[1000];
//        private static final int DELTA = 200;
//
//        // l,r <= 10^8
//
//        // r not included
//        public void increase(int l, int r, int s) {
//            for (int i = l + DELTA; i < r + DELTA; i++) {
//                wall[i] = Math.max(wall[i], s);
//            }
//        }
//
//        // r not included
//        public int getMin(int l, int r) {
//            int min = Integer.MAX_VALUE;
//            for (int i = l + DELTA; i < r + DELTA; i++) {
//                min = Math.min(min, wall[i]);
//            }
//            return min;
//        }
//    }

    public static class Node {
        final int l;
        final int r;
        final int m;
        int s; // min value
        int bulkS; // bulk s

        Node left;
        Node right;

        public Node(int l, int r) {
            assert r > l;
            this.l = l;
            this.r = r;
            this.m = (l + r) / 2;

            // left = l..m
            // right = m+1, r
        }

        public void increase(int ll, int rr, int ss) {
            if (ll == rr) {
                throw new RuntimeException();
            }

            if (ll == l && rr == r) {
                bulkS = Math.max(ss, bulkS);
                updateS();
                return;
            }

            if (left == null) {
                left = new Node(l, m);
            }
            if (right == null) {
                right = new Node(m, r);
            }

            if (rr <= m) {
                left.increase(ll, rr, ss);
            } else if (ll >= m) {
                right.increase(ll, rr, ss);
            } else {
                left.increase(ll, m, ss);
                right.increase(m, rr, ss);
            }

            updateS();
        }

        private void updateS() {
            s = Math.max(bulkS, Math.min(left == null ? bulkS : left.s, right == null ? bulkS : right.s));
        }

        public int getMin(int ll, int rr) {
            if (ll == rr) {
                throw new RuntimeException();
            }

            if (ll == l && rr == r) {
                return s;
            }
            // divide into two parts
            if (rr <= m) {
                if (left == null) {
                    return bulkS;
                } else {
                    return Math.max(bulkS, left.getMin(ll, rr));
                }
            }
            if (ll >= m) {
                if (right == null) {
                    return bulkS;
                } else {
                    return Math.max(bulkS, right.getMin(ll, rr));
                }
            }

            int leftR = (left == null ? bulkS : left.getMin(ll, m));
            int rightR = (right == null ? bulkS : right.getMin(m, rr));

            return Math.max(bulkS, Math.min(leftR, rightR));
        }
    }
}
