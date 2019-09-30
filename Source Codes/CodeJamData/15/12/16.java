import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author AlexFetisov
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    int count;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        count = in.nextInt();
        int n = in.nextInt();
        int[] times = Utils.readIntArray(in, count);

        long left = 0, right = (long)1e18;
        long middle;
        long resT = -1;
        out.print("Case #" + testNumber + ": ");

        while (left <= right) {
            middle = (left + right) / 2;

            Pair<Long, Long> p = getAmCustomers(times, middle);

            if (p.first >= n) {
                right = middle - 1;
            } else {
                if (p.first + p.second < n) {
                    left = middle + 1;
                } else {
                    resT = middle;
                    right = middle - 1;
                }
            }
        }

        Pair<Long, Long> p = getAmCustomers(times, resT);
        n -= p.first;
        for (int i = 0; i < count; ++i) {
            if (free[i]) {
                --n;
                if (n == 0) {
                    out.println(i + 1);
                    return;
                }
            }
        }
        throw new AssertionError("!");
    }

    Pair<Long, Long> getAmCustomers(int[] times, long t) {
        free = new boolean[count];
        long served = 0;
        long freed = 0;
        for (int i = 0; i < count; ++i) {
            if (t % times[i] == 0) {
                free[i] = true;
                ++freed;
                served += (t / times[i]);
            } else {
                free[i] = false;
                served += (t / times[i]) + 1;
            }
        }
        return Pair.makePair(served, freed);
    }

    boolean[] free;
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }
}

class Utils {
    public static int[] readIntArray(InputReader in, int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        return a;
    }

}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

