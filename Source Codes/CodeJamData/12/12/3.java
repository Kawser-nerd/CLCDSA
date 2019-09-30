import java.util.*;
import java.math.*;
import java.io.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Long.*;

public class QB {
    static String[] parts(BufferedReader br) throws Exception {
        String line = br.readLine();
        if (line == null) return null;
        return line.trim().split("\\s+");
    }
    static class Obj implements Comparable<Obj> {
        int a, b;
        boolean ga, gb;
        Obj(int c, int d) {
            a = c;
            b = d;
            ga = gb = false;
        }
        public int compareTo(Obj o) {
            if (b != o.b) return o.b - b;
            return a - o.a;
        }
        public boolean equals(Object o) {
            return o instanceof Obj && compareTo((Obj)o) == 0;
        }
    }
    static Obj o[] = new Obj[11111];
    static int stars;
    static int n;
    static PriorityQueue<Obj> pq = new PriorityQueue<Obj>();
    static void incstars(int a) {
        int add = a;
        while (add > 0) {
            stars += add;
            add = 0;
            for(int i = 0; i < n; i++) {
                if (o[i].b <= stars) {
                    if (o[i].gb) continue;
                    if (o[i].ga) {
                        add++;
                        o[i].gb = true;
                    } else {
                        o[i].ga = o[i].gb = true;
                        add += 2;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (o[i].ga) continue;
            if (o[i].a <= stars) {
                pq.add(o[i]);
            }
        }
    }   
    public static void main (String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int z = parseInt(br.readLine().trim());
        for (int cas = 1; cas <= z; cas++) {
            String p[] = parts(br);
            n = parseInt(p[0]);
            pq.clear();
            for (int i = 0; i < n; i++) {
                p = parts(br);
                int a = parseInt(p[0]);
                int b = parseInt(p[1]);
                o[i] = new Obj(a, b);
            }
            stars = -1;
            incstars(1);
            int st = n << 1;
            int move = n;
            while (stars < st && pq.size() > 0) {
                //out.println(pq.size() + " polling (" + stars + ")");
                Obj x = pq.poll();
                while (x.ga && pq.size() > 0) {
                    x = pq.poll();
                }
                if (x.ga) break;
                //out.println(pq.size() + " polling " + x.a + " " + x.b);
                move++;
                x.ga = true;
                incstars(1);
            }
            String ans = stars < st ? "Too Bad" : "" + move;
            out.println("Case #" + cas + ": " + ans);
        }
    }
}
