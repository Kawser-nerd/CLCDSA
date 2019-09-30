import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.util.HashSet;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Set;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			final String regex = "D-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
	int from = 0;
	int to = -1;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.err.println(testNumber);
		from = 0;
		to = -1;
		int count = in.readInt();
		int size = in.readInt();
		int variants = in.readInt();
		int[][] sets = IOUtils.readIntTable(in, count, size);
		go(0, count - 1, sets, variants);
        out.printLine("Case #" + testNumber + ":", from, to);
    }

	private void go(int left, int right, int[][] sets, int variants) {
		if (left == right) {
			if (to - from < 0) {
				from = left;
				to = left;
				return;
			}
		}
//		if (right - left > 10)
//			System.err.println(left + " " + right);
		int middle = (left + right) >> 1;
		for (int i : sets[middle]) {
			Set<Integer> current = new HashSet<Integer>();
			current.add(i);
			build(left, right, middle, middle, sets, variants - 1, current, true);
		}
		if (middle > left)
			go(left, middle - 1, sets, variants);
		if (middle < right)
			go(middle + 1, right, sets, variants);
	}

	private void build(int left, int right, int start, int end, int[][] sets, int remaining, Set<Integer> current, boolean canBuildDown) {
		while (start > left && canBuildDown) {
			boolean found = false;
			for (int i : sets[start - 1]) {
				if (current.contains(i)) {
					found = true;
				}
			}
			if (!found)
				break;
			start--;
		}
		while (end < right) {
			boolean found = false;
			for (int i : sets[end + 1]) {
				if (current.contains(i)) {
					found = true;
				}
			}
			if (!found)
				break;
			end++;
		}
		if (end - start > to - from || end - start == to - from && start < from) {
			from = start;
			to = end;
		}
		if (remaining > 0 && start > left && canBuildDown) {
			for (int i : sets[start - 1]) {
				current.add(i);
				build(left, right, start - 1, end, sets, remaining - 1, current, true);
				current.remove(i);
			}
		}
		if (remaining > 0 && end < right) {
			for (int i : sets[end + 1]) {
				current.add(i);
				build(left, right, start, end + 1, sets, remaining - 1, current, false);
				current.remove(i);
			}
		}
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

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

	}

