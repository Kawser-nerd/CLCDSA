
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {

    private static final long MOD = 1000002013;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        List<Event> events = new ArrayList<Event>();
        long res = 0;
        for (int i = 0; i < m; i++) {
            long a = in.nextInt();
            long b = in.nextInt();
            long p = in.nextInt();
            long d = b - a;
            res += (cost(d, n) * p) % MOD;
            res %= MOD;
            events.add(new Event(true, a, p));
            events.add(new Event(false, b, p));
        }
        Collections.sort(events);
        List<Event> ins = new ArrayList<Event>();
        for (Event event : events) {
            if (event.in) {
                ins.add(event);
            } else {
                while (event.num > 0) {
                    Event event1 = ins.remove(ins.size() - 1);
                    long p = Math.min(event.num, event1.num);
                    res += MOD - (cost(event.pos - event1.pos, n) * p) % MOD;
                    event.num -= p;
                    event1.num -= p;
                    if (event1.num > 0) {
                        ins.add(event1);
                    }
                    res %= MOD;
                }
            }
        }
        return "" + res;
    }

    private long cost(long d, long n) {
        return (n * d - d * (d - 1) / 2) % MOD;
    }

    class Event implements Comparable<Event>{
        boolean in;
        long pos;
        long num;

        Event(boolean in, long pos, long num) {
            this.in = in;
            this.pos = pos;
            this.num = num;
        }

        public int compareTo(Event o) {
            if (pos != o.pos) {
                return Long.compare(pos, o.pos);
            } else {
                if (in == o.in) return 0;
                return in ? -1 : 1;
            }
        }
    }
}