import java.util.*;
import java.math.*;
import java.io.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Long.*;

public class QC {
    static String[] parts(BufferedReader br) throws Exception {
        String line = br.readLine();
        if (line == null) return null;
        return line.trim().split("\\s+");
    }
    static class rat implements Comparable<rat> {
        BigInteger n, d;
        rat(long a, long b) {
            this(BigInteger.valueOf(a), BigInteger.valueOf(b));
        }
        rat(BigInteger a, BigInteger b) {
            BigInteger g = a.gcd(b);
            n = a.divide(g);
            d = b.divide(g);
            if (d.signum() < 0) {
                n = n.negate();
                d = d.negate();
            }
        }
        rat add(rat r) {
            return new rat(n.multiply(r.d).add(d.multiply(r.n)), d.multiply(r.d));
        }
        rat sub(rat r) {
            return new rat(n.multiply(r.d).subtract(d.multiply(r.n)), d.multiply(r.d));
        }
        rat mul(rat r) {
            return new rat(n.multiply(r.n), d.multiply(r.d));
        }
        rat div(rat r) {
            return new rat(n.multiply(r.d), d.multiply(r.n));
        }
        int signum() {
            return n.signum() / d.signum();
        }
        public int compareTo(rat r) {
            return sub(r).signum();
        }
        public boolean equals(Object o) {
            return o instanceof rat && compareTo((rat)o) == 0;
        }
        rat abs() {
            return signum() < 0 ? new rat(n.negate(), d) : this;
        }
        double doubleValue() {
            return n.doubleValue() / d.doubleValue();
        }
        public String toString() {
            return n + "/" + d;
        }
    }
    static rat f = new rat(5, 1);
    static rat ff = new rat(10, 1);
    static void changelanes(int n, rat ps[], HashSet<Integer> lanes, int c) {
        boolean clear[] = new boolean[n];
        boolean lf[] = des(c, n);
        // check bad, populate clear
        ///if (cas == 3)out.println(c + ": " + Arrays.toString(lf));
        for (int i = 0; i < n; i++) {
            clear[i] = true;
            for (int j = 0; j < i; j++) {
                if (ps[i].sub(ps[j]).abs().compareTo(f) < 0) {
                    if (lf[i] == lf[j]) {// overlap!
                        ///if (cas == 3)out.println("overlap! " + j + " " + i);
                        return; 
                    }
                    clear[i] = false; // cannot move
                }
            }
        }
        for (int d = 0; d < 1 << n; d++) {
            if (lanes.contains(d)) continue;
            boolean gf[] = des(d, n);
            boolean good = true;
            for (int i = 0; i < n; i++) {
                if (lf[i] != gf[i]) {
                    if (!clear[i]) {
                        good = false;
                        break;
                    }
                }
            }
            if (good) {
                lanes.add(d);
            }
        }
    }static int cas;
    static int ser(boolean b[], int n) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            x <<= 1;
            x |= b[i] ? 1 : 0;
        }
        return x;
    }
    static boolean[] des(int c, int n) {
        boolean b[] = new boolean[n];
        for (int i = n - 1; i >= 0; i--) {
            b[i] = (c & 1) != 0;
            c >>= 1;
        }
        return b;
    }
    static String bits(int c, int n) {
        boolean b[] = des(c, n);
        String s = "";
        for (int i = 0; i < n; i++) if (!b[i]) {
            s += (b[i] ? "#" : ".");
        }
        return s;
    }
    public static void main (String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int z = parseInt(br.readLine().trim());
        int s[] = new int[1111];
        int d[] = new int[1111];
        rat rs[] = new rat[1111];
        rat rd[] = new rat[1111];
        rat ps[] = new rat[1111];
        rat e = new rat(1, 100000000000000000L);
        TreeSet<rat> times = new TreeSet<rat>();
        HashSet<Integer> lanes = new HashSet<Integer>();
        HashSet<Integer> lanes2 = new HashSet<Integer>();
        boolean ls[] = new boolean[1111];
        for ( cas = 1; cas <= z; cas++) {
            String p[] = parts(br);
            int n = parseInt(p[0]);
            err.println(cas + " " + n);
            lanes.clear();
            lanes2.clear();
            times.clear();
            for (int i = 0; i < n; i++) {
                p = parts(br);
                ls[i] = p[0].charAt(0) == 'L';
                s[i] = parseInt(p[1]);
                d[i] = parseInt(p[2]);
                rs[i] = new rat(s[i], 1);
                rd[i] = new rat(d[i], 1);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (s[i] != s[j]) {
                        //d[i] + s[i] * t = d[j] + s[j] * t
                        //(s[i] - s[j]) * t = d[j] - d[i]
                        rat t = new rat(d[j] - d[i], s[i] - s[j]);
                        if (t.signum() >= 0) {
                            times.add(t);
                            times.add(t.add(e));
                            times.add(t.sub(e));
                        }
                        t = new rat(d[j] - d[i] + 5, s[i] - s[j]);
                        if (t.signum() >= 0) {
                            times.add(t);
                            times.add(t.add(e));
                            times.add(t.sub(e));
                        }
                        t = new rat(d[j] - d[i] - 5, s[i] - s[j]);
                        if (t.signum() >= 0) {
                            times.add(t);
                            times.add(t.add(e));
                            times.add(t.sub(e));
                        }
                    }
                }
            }
            rat rz = new rat(0, 1);
            times.remove(rz);
            int l = ser(ls, n);
            changelanes(n, rd, lanes, l);
            ///if (cas == 3)out.println("sz = " + lanes.size());
            for (Integer c : lanes) {
                ///if (cas == 3)out.println(bits(c, n));
            }
            rat ans = null;
            ///if (cas == 3)for (rat t : times) {
                ///if (cas == 3)out.println(",,,,,, " + t.doubleValue());
            ///if (cas == 3);}
            for (rat t : times) {
                lanes2.clear();
                ///if (cas == 3)out.println("------------------------");
                ///if (cas == 3)out.println("t = " + t.doubleValue());
                for (int i = 0; i < n; i++) {
                    ps[i] = rd[i].add(rs[i].mul(t));
                    ///if (cas == 3)out.println(s[i] + " " + d[i] + ": " + ps[i].doubleValue());
                }
                for (Integer c : lanes) {
                    ///if (cas == 3)out.println(bits(c, n));
                    changelanes(n, ps, lanes2, c);
                }
                if (lanes2.size() == 0) {
                    ///if (cas == 3)out.println("*** bad!");
                    ans = t;
                    break;
                }
                HashSet<Integer> temp = lanes; lanes = lanes2; lanes2 = temp;
            }
            
            out.println("Case #" + cas + ": " + (ans == null ? "Possible" : ans.doubleValue()));
        }
    }
}
