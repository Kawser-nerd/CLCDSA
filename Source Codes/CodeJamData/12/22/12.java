import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.io.PrintStream;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.util.ArrayDeque;
import java.io.FileInputStream;
import java.util.Queue;
import java.math.BigInteger;
import java.util.Collections;
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
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.err.println(testNumber);
		int waterLevel = in.readInt();
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int[][] ceiling = IOUtils.readIntTable(in, rowCount, columnCount);
		int[][] floor = IOUtils.readIntTable(in, rowCount, columnCount);
		final double[][] answer = new double[rowCount][columnCount];
		ArrayUtils.fill(answer, Double.POSITIVE_INFINITY);
		answer[0][0] = 0;
		Queue<Pair<Integer, Integer>> queue = new ArrayDeque<Pair<Integer, Integer>>();
		queue.add(Pair.makePair(0, 0));
		while (!queue.isEmpty()) {
			int row = queue.peek().first;
			int column = queue.poll().second;
			for (int i = 0; i < 4; i++) {
				int newRow = row + MiscUtils.DX4[i];
				int newColumn = column + MiscUtils.DY4[i];
				if (newRow >= 0 && newRow < rowCount && newColumn >= 0 && newColumn < columnCount
					&& answer[newRow][newColumn] != 0 && Math.min(ceiling[newRow][newColumn], ceiling[row][column]) >=
					50 + Math.max(waterLevel, Math.max(floor[newRow][newColumn], floor[row][column])))
				{
					answer[newRow][newColumn] = 0;
					queue.add(Pair.makePair(newRow, newColumn));
				}
			}
		}
		boolean[][] processed = new boolean[rowCount][columnCount];
		queue = new PriorityQueue<Pair<Integer, Integer>>(rowCount * columnCount, new Comparator<Pair<Integer, Integer>>() {
			public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
				return Double.compare(answer[o1.first][o1.second], answer[o2.first][o2.second]);
			}
		});
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (answer[i][j] == 0)
					queue.add(Pair.makePair(i, j));
			}
		}
		while (!queue.isEmpty()) {
			int row = queue.peek().first;
			int column = queue.poll().second;
			if (processed[row][column])
				continue;
			processed[row][column] = true;
			for (int i = 0; i < 4; i++) {
				int newRow = row + MiscUtils.DX4[i];
				int newColumn = column + MiscUtils.DY4[i];
				if (newRow >= 0 && newRow < rowCount && newColumn >= 0 && newColumn < columnCount && answer[newRow][newColumn] != 0) {
					if (Math.min(ceiling[newRow][newColumn], ceiling[row][column]) < 50 + Math.max(floor[newRow][newColumn], floor[row][column]))
						continue;
					double firstTimePassable = (waterLevel - Math.min(ceiling[newRow][newColumn], ceiling[row][column]) + 50) / 10d;
					double curTime = Math.max(firstTimePassable, answer[row][column]);
					double curWaterLevel = waterLevel - 10 * curTime;
					if (curWaterLevel - floor[row][column] > 20 - GeometryUtils.epsilon)
						curTime++;
					else
						curTime += 10;
					if (answer[newRow][newColumn] > curTime) {
						answer[newRow][newColumn] = curTime;
						queue.add(Pair.makePair(newRow, newColumn));
					}
				}
			}
		}
		out.printLine("Case #" + testNumber + ":", answer[rowCount - 1][columnCount - 1]);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
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
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public String next() {
		return readString();
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

class ArrayUtils {

	public static void fill(double[][] array, double value) {
		for (double[] row : array)
			Arrays.fill(row, value);
	}

	}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
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

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

	}

class GeometryUtils {
	public static double epsilon = 1e-8;

	}

