import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int time = in.readInt();
		int size = in.readInt();
		int[] start = new int[count];
		int[] end = new int[count];
		int[] enter = new int[count];
		int[] duration = new int[count];
		IOUtils.readIntArrays(in, start, end, enter);
		MiscUtils.decreaseByOne(start, end);
		for (int i = 0; i < count; i++) {
			duration[i] = end[i] - start[i];
			if (duration[i] < 0)
				duration[i] += size;
			duration[i] *= 2;
			start[i] += enter[i];
			start[i] %= size;
			end[i] = start[i] + 2 * duration[i];
			end[i] %= size;
		}
		int[] interesting = new int[Math.max(4 * count, 1)];
		for (int i = 0; i < count; i++) {
			interesting[4 * i] = start[i];
			interesting[4 * i + 1] = start[i] == 0 ? size - 1 : start[i] - 1;
			interesting[4 * i + 2] = end[i] == size - 1 ? 0 : end[i] + 1;
			interesting[4 * i + 3] = end[i];
		}
		if (count == 0)
			interesting[0] = 0;
		int[] bad = new int[2 * count];
		int answer = 0;
		for (int i : interesting) {
			int qty = 0;
			for (int j = 0; j < count; j++) {
				int distance = i - start[j];
				if (distance < 0)
					distance += size;
				while (distance <= duration[j]) {
					bad[qty++] = 2 * enter[j] + distance;
					distance += size;
				}
			}
			Arrays.sort(bad, 0, qty);
			int from = 0;
			for (int j = 0; j < qty; j++) {
				int to = bad[j] - 1;
				to -= to & 1;
				answer = Math.max(answer, to - from);
				from = bad[j] + 1;
				from += from & 1;
			}
			answer = Math.max(answer, 2 * time - from);
		}
        out.printLine("Case #" + testNumber + ":", answer / 2);
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

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

class MiscUtils {

    public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}

