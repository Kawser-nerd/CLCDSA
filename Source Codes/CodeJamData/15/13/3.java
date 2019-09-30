import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("taskc.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskc.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            points[i] = new Point(in.nextInt(), in.nextInt());
        }
        Event[] temp = new Event[n - 1];
        out.println("Case #" + testNumber + ":");
        for (int ourPoint = 0; ourPoint < n; ourPoint++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j != ourPoint) {
                    Point diff = points[j].sub(points[ourPoint]);
                    Point neg = new Point(-diff.x, -diff.y);
                    if (diff.side() > 0) {
                        temp[cnt++] = new Event(diff, true);
                    } else {
                        temp[cnt++] = new Event(neg, false);
                    }
                }
            }
            Arrays.sort(temp);
            int count = 0;
            for (Event e : temp) {
                if (e.ok) {
                    count++;
                }
            }
            int bestAnswer = Integer.MAX_VALUE;
            for (int i = 0; i < temp.length; ) {
                int j = i + 1;
                while (j < temp.length && temp[i].compareTo(temp[j]) == 0) {
                    j++;
                }
                int curPositive = 0;
                int curNegative = 0;
                for (int it = i; it < j; it++) {
                    if (temp[it].ok) ++curPositive;
                    else ++curNegative;
                }
                int curAnswer = Math.min(count - curPositive, n - 1 - count - curNegative);
                bestAnswer = Math.min(bestAnswer, curAnswer);
                count += curNegative - curPositive;
                i = j;
            }
            if (n == 1) {
                bestAnswer = 0;
            }
            out.println(bestAnswer);
        }
        System.err.println("done " + testNumber);
    }

    static class Event implements Comparable<Event> {
        Point p;
        boolean ok;

        Event(Point p, boolean ok) {
            this.p = p;
            this.ok = ok;
        }

        public int compareTo(Event o) {
            return p.compareTo(o.p);
        }
    }

    static class Point implements Comparable<Point> {
        long x, y;

        Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        long vmul(Point p) {
            return x * p.y - y * p.x;
        }

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        int side() {
            return y > 0 || (y == 0 && x > 0) ? -1 : 1;
        }

        public int compareTo(Point o) {
            int c = side() - o.side();
            if (c != 0) {
                return c;
            }
            return -Long.signum(vmul(o));
        }
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String next() {
        return nextToken();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}

