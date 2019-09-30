import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class E {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("E.in"));
        PrintWriter out = new PrintWriter("E.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int n = in.nextInt();
        Map<String, Integer> mm = new HashMap<String, Integer>();
        List<Segment> s = new ArrayList<Segment>();
        for (int i = 0; i < 2 * n; i++) {
            String ss = in.next();
            if (mm.get(ss) == null) {
                mm.put(ss, i);
            } else {
                s.add(new Segment(mm.get(ss), i));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Segment a = s.get(i);
                Segment b = s.get(j);
                if (a.a < b.a && b.a < a.b && a.b < b.b) {
                    a.opp.add(b);
                    b.opp.add(a);
                }
            }
        }

        List<Part> parts = new ArrayList<Part>();
        for (int i = 0; i < n; i++) {
            if (!s.get(i).z) {
                Part p = new Part();
                if (!dfs(s.get(i), p, true)) {
                    return "-1";
                }
                parts.add(p);
            }
        }

        int m = parts.size();
        int res = 100000;
        for (int ms = 0; ms < (1 << m); ms++) {
            for (int i = 0; i < m; i++) {
                int k = (ms >> i) & 1;
                for (Segment segment : parts.get(i).l) {
                    segment.p = k;
                }
                for (Segment segment : parts.get(i).r) {
                    segment.p = 1 - k;
                }
            }
            int[] d = new int[n];
            int[] dd = new int[2];
            for (int i = 0; i < n; i++) {
                d[i] = 1;
                for (int j = 0; j < i; j++) {
                    if (s.get(j).a > s.get(i).a && s.get(i).p == s.get(j).p) {
                        d[i] = Math.max(d[i], d[j] + 1);
                    }
                }
                dd[s.get(i).p] = Math.max(dd[s.get(i).p], d[i]);
            }
            res = Math.min(res, dd[0] + dd[1]);
        }

        return "" + res;
    }

    private static boolean dfs(Segment s, Part p, boolean l) {
        if (s.z) {
            return !(l && p.r.contains(s) ||
                    !l && p.l.contains(s));
        }
        if (l) p.l.add(s); else p.r.add(s);
        s.z = true;
        for (Segment t : s.opp) {
            if (!dfs(t, p, !l)) return false;
        }
        return true;
    }

    static class Segment {
        int a;
        int b;

        boolean z;
        int p;

        Set<Segment> opp = new HashSet<Segment>();

        Segment(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    static class Part {
        Set<Segment> l = new HashSet<Segment>();
        Set<Segment> r = new HashSet<Segment>();
    }

}