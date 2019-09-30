
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class TicketSwapping implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new TicketSwapping(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("/home/megaterik/ticket.in"));
            out = new PrintWriter("src/ticketswapping.txt");

            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    void solve() throws IOException {
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            solveTestCase(++n);
        }
    }
    static final long modulo = 1000002013L;

    class Pair implements Comparable<Pair> {

        long remains;
        long from;

        Pair(long from, long remains) {
            this.from = from;
            this.remains = remains;
        }

        @Override
        public int compareTo(Pair o) {
            return Long.compare(o.from, this.from);//reverse order
        }
    }

    void solveTestCase(int number) throws IOException {
        HashMap<Long, Long> enteringCounter = new HashMap<>();
        HashMap<Long, Long> exitingCounter = new HashMap<>();
        TreeSet<Long> interestingPlaces = new TreeSet<>();
        PriorityQueue<Pair> maxheap = new PriorityQueue<Pair>();
        long n = readLong();
        int m = readInt();
        long sum = 0;
        for (int i = 0; i < m; i++) {
            long from = readLong();
            long to = readLong();
            long count = readLong();
            long distance = to - from + 1;

            sum = (sum + count * (((n + (n - distance + 1)) * distance / 2) % modulo)) % modulo;
            //  System.out.println("+ " + (n + (n - distance + 1)) * distance / 2);
            interestingPlaces.add(from);
            interestingPlaces.add(to);
            if (enteringCounter.containsKey(from)) {
                enteringCounter.put(from, enteringCounter.get(from) + count);
            } else {
                enteringCounter.put(from, count);
            }
            if (exitingCounter.containsKey(to)) {
                exitingCounter.put(to, exitingCounter.get(to) + count);
            } else {
                exitingCounter.put(to, count);
            }
        }

       // System.out.println(Arrays.deepToString(interestingPlaces.toArray()));

        for (Long location : interestingPlaces) {
            long entering = (enteringCounter.containsKey(location) ? enteringCounter.get(location) : 0);
            long exiting = (exitingCounter.containsKey(location) ? exitingCounter.get(location) : 0);
            //System.out.println(entering + " " + exiting + " at " + location);
            maxheap.add(new Pair(location, entering));
            while (exiting > 0) {
                Pair p = maxheap.poll();
                if (p.remains > exiting) {
                    p.remains -= exiting;
                    long distance = location - p.from + 1;
                    sum = (sum - exiting * (((n + (n - distance + 1)) * distance / 2) % modulo)) % modulo;
                    exiting = 0;
                    maxheap.add(p);
                    continue;
                } else {
                    long distance = location - p.from + 1;
                    exiting -= p.remains;
                    sum = (sum - p.remains * (((n + (n - distance + 1)) * distance / 2) % modulo)) % modulo;
                    p.remains = 0;
                }
            }
        }
        sum = (sum + modulo) % modulo;
        out.println("Case #" + number + ": " + sum);
    }
}