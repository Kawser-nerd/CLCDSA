import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.PriorityQueue;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    static class Hiker {
        int startPos;
        int period;
        int id;

        public Hiker(int startPos, int period, int id) {
            this.startPos = startPos;
            this.period = period;
            this.id = id;
        }
    }

    static class Event implements Comparable<Event> {
        long nextTime;
        boolean first;
        Hiker h;

        public Event(long nextTime, boolean first, Hiker h) {
            this.nextTime = nextTime;
            this.first = first;
            this.h = h;
        }

        public int compareTo(Event o) {
            if (nextTime != o.nextTime) return Long.compare(nextTime, o.nextTime);
            return Integer.compare(h.id, o.h.id);
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println("[" + testNumber + "]");
        int dontUseThisN = in.nextInt();
        List<Hiker> hikers = new ArrayList<>();
        for (int i = 0; i < dontUseThisN; i++) {
            int start = in.nextInt();
            int count = in.nextInt();
            int time = in.nextInt();
            for (int j = 0; j < count; j++) hikers.add(new Hiker(start, time + j, hikers.size()));
        }
        PriorityQueue<Event> events = new PriorityQueue<>();
        Hiker[] a = hikers.toArray(new Hiker[hikers.size()]);
        for (int i = 0; i < a.length; i++) {
            events.add(new Event((360L - a[i].startPos) * a[i].period, true, a[i]));
        }
        int ans = Integer.MAX_VALUE;
        long lastTime = Long.MIN_VALUE;
        int balance = a.length;
        for (int i = 0; i < 6 * a.length; i++) {
            Event current = events.poll();
            if (current.nextTime != lastTime) ans = Math.min(ans, balance);
            if (current.first) --balance; else ++balance;
            Event newEvent = new Event(current.nextTime + 360L * current.h.period, false, current.h);
            events.add(newEvent);
            lastTime = current.nextTime;
        }
        out.println("Case #" + testNumber + ": " + ans);
    }

}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}

