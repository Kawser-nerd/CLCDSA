import java.util.concurrent.atomic.AtomicInteger;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.Arrays;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.File;

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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	int[] result;
	AtomicInteger solved = new AtomicInteger(0);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int testCount = in.readInt();
		result = new int[testCount];
		for (int i = 0; i < testCount; i++) {
			int width = in.readInt();
			int height = in.readInt();
			int count = in.readInt();
			int[] x0 = new int[count];
			int[] y0 = new int[count];
			int[] x1 = new int[count];
			int[] y1 = new int[count];
			IOUtils.readIntArrays(in, x0, y0, x1, y1);
			x0 = Arrays.copyOf(x0, count + 1);
			x1 = Arrays.copyOf(x1, count + 1);
			y0 = Arrays.copyOf(y0, count + 1);
			y1 = Arrays.copyOf(y1, count + 1);
			y1[count] = height - 1;
			new Thread(new Solver(i, width, height, count, x0, y0, x1, y1)).start();
		}
		while (solved.get() != testCount) {
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		for (int i = 0; i < testCount; i++)
			out.printLine("Case #" + (i + 1) + ":", result[i]);
    }

	class Solver implements Runnable {
		int id;
		int width;
		int height;
		int count;
		int[] x0;
		int[] y0;
		int[] x1;
		int[] y1;

		Solver(int id, int width, int height, int count, int[] x0, int[] y0, int[] x1, int[] y1) {
			this.id = id;
			this.width = width;
			this.height = height;
			this.count = count;
			this.x0 = x0;
			this.y0 = y0;
			this.x1 = x1;
			this.y1 = y1;
		}

		public void run() {
			int answer = 0;
			boolean[] enlarge = new boolean[count + 1];
			x1[count] = -1;
			for (int i = 0; i < width; i++) {
				Arrays.fill(enlarge, false);
				int dx = 0;
				int dy = 1;
				int x = i;
				int y = 0;
				int current = -1;
				for (int j = 0; j <= count; j++) {
					if (x1[j] == i - 1 && y0[j] == 0) {
						current = j;
						break;
					}
				}
				if (current == -1)
					continue;
				while (y != height && y != -1 && x != width) {
					enlarge[current] = true;
					int next = -1;
					for (int j = 0; j <= count; j++) {
						if (x0[j] <= x && x <= x1[j] && y0[j] <= y && y <= y1[j]) {
							next = -2;
							break;
						}
						if (dy != 0 && x0[j] <= x && x <= x1[j]) {
							if (dy == 1 && y < y0[j]) {
								if (next == -1 || y0[j] < y0[next])
									next = j;
							} else if (dy == -1 && y > y1[j]) {
								if (next == -1 || y1[j] > y1[next])
									next = j;
							}
						} else if (dx != 0 && y0[j] <= y && y <= y1[j]) {
							if (dx == 1 && x < x0[j]) {
								if (next == -1 || x0[j] < x0[next])
									next = j;
							} else if (dx == -1 && x > x1[j]) {
								if (next == -1 || x1[j] > x1[next])
									next = j;
							}
						}
					}
					if (next == -2)
						break;
					if (next == -1 || dy == 1 && y0[next] > y1[current] + 1 || dy == -1 && y1[next] < y0[current] - 1 ||
						dx == 1 && x0[next] > x1[current] + 1 || dx == -1 && x1[next] < x0[current] - 1)
					{
						if (dy == 1)
							y = y1[current] + 1;
						if (dy == -1)
							y = y0[current] - 1;
						if (dx == 1)
							x = x1[current] + 1;
						if (dx == -1)
							x = x0[current] - 1;
						int ndx = -dy;
						dy = dx;
						dx = ndx;
					} else {
						if (dy == 1)
							y = y0[next] - 1;
						if (dy == -1)
							y = y1[next] + 1;
						if (dx == 1)
							x = x0[next] - 1;
						if (dx == -1)
							x = x1[next] + 1;
						current = next;
						int ndx = dy;
						dy = -dx;
						dx = ndx;
					}
				}
				if (y == height) {
					answer++;
					for (int j = 0; j <= count; j++) {
						if (enlarge[j]) {
							x0[j] = Math.max(x0[j] - 1, 0);
							y0[j] = Math.max(y0[j] - 1, 0);
							x1[j] = Math.min(x1[j] + 1, width - 1);
							y1[j] = Math.min(y1[j] + 1, height - 1);
						}
					}
				}
			}
			result[id] = answer;
			solved.incrementAndGet();
			System.err.println(id);
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

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

