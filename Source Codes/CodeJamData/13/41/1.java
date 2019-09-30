import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int cardId = 0;

    class Card implements Comparable<Card> {
        int id;
        long from;
        long cnt;

        @Override
        public int compareTo(Card o) {
            return from < o.from ? -1 : from > o.from ? 1 : id - o.id;
        }

        Card(long from, long cnt) {
            id = cardId++;
            this.from = from;
            this.cnt = cnt;
        }
    }

    class Event implements Comparable<Event> {
        boolean enter;
        long where;
        long cnt;

        Event(boolean enter, long where, long cnt) {
            this.enter = enter;
            this.where = where;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Event o) {
            if (where < o.where) {
                return -1;
            }
            if (where > o.where) {
                return 1;
            }
            if (enter && !o.enter) {
                return -1;
            }
            if (!enter && o.enter) {
                return 1;
            }
            return 0;
        }
    }

    BigInteger pay(long N, long from, long to) {
        return BigInteger.valueOf((N + (N - (to - from - 1))) * (to - from) / 2);
    }
    
    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);

            int N = in.nextInt();
            int M = in.nextInt();

            BigInteger payDef = BigInteger.ZERO;

            ArrayList<Event> events = new ArrayList<Event>();
            for (int i = 0; i < M; i++) {
                long from = in.nextInt();
                long to = in.nextInt();
                long cnt = in.nextInt();
                payDef = payDef.add(pay(N, from, to).multiply(BigInteger.valueOf(cnt)));
                events.add(new Event(true, from, cnt));
                events.add(new Event(false, to, cnt));
            }

            Collections.sort(events);

            TreeSet<Card> cards = new TreeSet<Card>();

            BigInteger doPay = BigInteger.ZERO;
            long sum = 0;
            for (Event e : events) {
                if (e.enter) {
                    Card c = new Card(e.where, e.cnt);
                    cards.add(c);
                } else {
                    while (e.cnt > 0) {
                        Card c = cards.pollLast();
                        long use = Math.min(e.cnt, c.cnt);
                        doPay = doPay.add(pay(N, c.from, e.where).multiply(BigInteger.valueOf(use)));
                        e.cnt -= use;
                        c.cnt -= use;
                        if (c.cnt > 0) {
                            cards.add(c);
                        }
                    }
                }
            }

            out("Case #%d: ", test);
            out("%d", payDef.subtract(doPay).mod(BigInteger.valueOf(1000002013L)));
            out("\n");
        }
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new A().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}