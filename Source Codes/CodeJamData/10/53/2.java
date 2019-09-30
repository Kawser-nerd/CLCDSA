package round3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class C {

    public static void main(String[] args) throws FileNotFoundException {

//        for (int n = 1; n <= 20; n++) {
//
//            int[] a = new int[n + 1];
//            a[n / 2] = n;
//            int s = 0;
//            while (true) {
//                boolean ok = true;
//                for (int i = 0; i <= n; i++) {
//                    if (a[i] > 1) {
//                        a[i - 1]++;
//                        a[i + 1]++;
//                        a[i] -= 2;
//                        s++;
//                        ok = false;
//                    }
//                }
//                if (ok) break;
//            }
//            System.out.println(n + " " + s);
//        }

//        if (true) return;
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int[] p = new int[n];
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
            v[i] = in.nextInt();
        }
        List<Segment> a = new ArrayList<Segment>();
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                a.add(new Segment(p[i] - v[i] / 2, p[i] - 1));
                a.add(new Segment(p[i] + 1, p[i] + v[i] / 2));
            } else {
                a.add(new Segment(p[i]- v[i] / 2, p[i] + v[i] / 2));
            }
        }
        while (true) {
            Collections.sort(a);
            int r = Integer.MIN_VALUE;
            Segment s1 = null;
            Segment s2 = null;
            for (Segment s : a) {
                if (s.l <= r) {
                    s2 = s;
                    break;
                } else {
                    if (s.r > r) {
                        s1 = s;
                        r = s.r;
                    }
                }
            }
            if (s2 != null) {
                a.remove(s1);
                a.remove(s2);
                int c = (s1.r - s1.l + s2.r - s2.l + 2);
                long q = s1.sum() + s2.sum();
                Segment zzz = new Segment(0, 0);
                int lo = -1000000000;
                int hi = 1000000000;
                while (hi > lo + 1) {
                    int me = (lo + hi) / 2;
                    zzz.l = me;
                    zzz.r = me + c - 1;
                    if (zzz.sum() > q) {
                        hi = me;
                    } else {
                        lo = me;
                    }
                }
                zzz.l = lo;
                zzz.r = lo + c - 1;
                //System.out.println(s1 + " " + s2);
                if (zzz.sum() == q) {
                    //System.out.println(" " + zzz);
                    a.add(zzz);
                } else {
                    int k = (int) (q - zzz.sum());
                    Segment zzz1 = new Segment(zzz.l, zzz.r - k);
                    Segment zzz2 = new Segment(zzz.r - k + 2, zzz.r + 1);
                    //System.out.println(" " + zzz1 + " " + zzz2);
                    //if (true) return "";
                    a.add(zzz1);
                    a.add(zzz2);
                }
            } else {
                break;
            }
        }
        Set<Integer> t = new HashSet<Integer>();
        Map<Integer, Integer> r1 = new HashMap<Integer, Integer>();
        Map<Integer, Integer> r2 = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            t.add(p[i]);
            r1.put(p[i], v[i]);
        }
        for (Segment segment : a) {
            for (int i = segment.l; i <= segment.r; i++) {
                t.add(i);
                if (r2.get(i) != null) throw new Error();
                r2.put(i, 1);
            }
        }
        List<Integer> b = new ArrayList<Integer>(t);
        Collections.sort(b);
        int pi = Integer.MIN_VALUE;
        long s = 0;
        long g = 0;
        long u = 0;
        int min = b.get(0);
        int max = b.get(b.size() - 1);
        for (int i = min; i <= max; i++) {
            Integer c1 = r1.get(i);
            Integer c2 = r2.get(i);
            if (c1 == null) c1 = 0;
            if (c2 == null) c2 = 0;
            long z = c1 + u;
            s += g;
            z -= 2 * g;
            if (z > c2) throw new Error();
            u = g;
            g = c2 - z;
        }
        return "" + s;
    }

    class Segment implements Comparable<Segment>{
        Segment(int l, int r) {
            this.l = l;
            this.r = r;
        }
        int l, r;

        public int compareTo(Segment segment) {
            return l - segment.l;
        }

        public long sum() {
            long c = r - l + 1;
            return c * l + (c - 1) * c / 2;
        }

        @Override
        public String toString() {
            return l + "-" + r;
        }
    }
}