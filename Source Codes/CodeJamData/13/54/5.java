import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
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
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
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
	double[][] answer = new double[21][];

	{
		for (int i = 0; i <= 20; i++)
			answer[i] = new double[1 << i];
		ArrayUtils.fill(answer, -1);
	}

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] description = in.readString().toCharArray();
		int mask = 0;
		for (int i = 0; i < description.length; i++) {
			if (description[i] == 'X')
				mask += 1 << i;
		}
		out.printLine("Case #" + testNumber + ":", calculate(description.length, mask));
    }

	private double calculate(int count, int mask) {
		if (Integer.bitCount(mask) == count)
			return 0;
		while ((mask & (1 << (count - 1))) != 0)
			mask = (mask << 1) + 1 - (1 << count);
		if (answer[count][mask] != -1)
			return answer[count][mask];
		answer[count][mask] = 0;
		for (int i = 0; i < count; i++) {
			if ((mask >> i & 1) == 0) {
				double total = count;
				int multiplier = 1;
				for (int j = i - 1; j >= 0; j--) {
					if ((mask >> j & 1) == 0)
						break;
					total += count - multiplier;
					multiplier++;
				}
				answer[count][mask] += multiplier * calculate(count, mask + (1 << i)) + total;
			}
		}
		return answer[count][mask] /= count;
	}
}

class ArrayUtils {

	public static void fill(double[][] array, double value) {
		for (double[] row : array)
			Arrays.fill(row, value);
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

