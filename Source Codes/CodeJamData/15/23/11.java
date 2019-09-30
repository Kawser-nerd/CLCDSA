import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Jacob Jiang
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public static final double EPS = 1e-11;

    private class Person {
        int d;
        int m;

        public Person(int d, int m) {
            this.d = d;
            this.m = m;
        }

        public String toString() {
            return "Person{" +
                    "d=" + d +
                    ", m=" + m +
                    '}';
        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        List<Person> list = readData(in);
        Collections.sort(list, new Comparator<Person>() {
            public int compare(Person o1, Person o2) {
                if (o1.d == o2.d)
                    return Integer.compare(o1.m, o2.m);
                return Integer.compare(o1.d, o2.d);
            }
        });
        int answer = 0;
        if (list.size() > 1) {
            Person first = list.get(0);
            Person second = list.get(1);
            if (first.m < second.m) {
                double d = second.d + (double) (second.d - first.d) * first.m / (second.m - first.m);
                double t = 360.0 * first.m / (second.m - first.m);
                if (d + t < 360 + EPS) {
                    answer = 1;
                }
            } else if (first.m > second.m) {
                second.d -= 360;
                Person tmp = first;
                first = second;
                second = tmp;
                double d = second.d + (double) (second.d - first.d) * first.m / (second.m - first.m);
                double t = second.d + 360.0 * first.m / (second.m - first.m);
                if (d < 360 + EPS) {
                    answer = 1;
                }
            }
        }
        out.println("Case #" + testNumber + ": " + answer);

    }

    private List<Person> readData(InputReader in) {
        List<Person> result = new ArrayList<>();
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int d = in.nextInt();
            int h = in.nextInt();
            int m = in.nextInt();
            for (int j = 0; j < h; j++) {
                result.add(new Person(d, m + j));
            }
        }
        return result;
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public void println(String x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

}

