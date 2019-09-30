import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.PrintStream;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
    static final char CELL = 'X';
    static final char EMPTY = '.';

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        out.printFormat("Case #%d: ", testNumber);
        int n = in.readInt();
        int m = in.readInt();
        int k = in.readInt();
        int maxInner = 0;
        char[][] a = new char[n][m];
        for (int mask = 0; mask < (1 << (n*m)); mask++) {
            if (Integer.bitCount(mask) != k) {
                continue;
            }
            ArrayUtils.fill(a, EMPTY);
            for (int bit = 0; bit < n*m; bit++) {
                if ((mask & (1 << bit)) != 0) {
                    int x = bit / m;
                    int y = bit % m;
                    a[x][y] = CELL;
                }
            }
            int inner = getInner(a, n, m);
            if (inner > maxInner) {
                maxInner = inner;
                System.err.println("inner = " + inner);
                System.err.println(Arrays.deepToString(a));
            }
        }
        out.printLine(k - maxInner);
    }

    private int getInner(char[][] a, int n, int m) {
        int cnt = 0;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (a[i][j] == EMPTY) {
                    continue;
                }
                boolean isInner = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i + MiscUtils.DX4[k];
                    int ny = j + MiscUtils.DY4[k];
                    if (a[nx][ny] == EMPTY) {
                        isInner = false;
                        break;
                    }
                }
                if (isInner) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

class InputReader {

    private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

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

    public int readInt() {
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
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

    public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

    public String next() {
		return readString();
	}

    public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

    public void printFormat(String format, Object...objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

    public void printLine(int i) {
		writer.println(i);
	}
}

class ArrayUtils {

    public static void fill(char[][] array, char value) {
		for (char[] row : array)
			Arrays.fill(row, value);
	}

}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

}

