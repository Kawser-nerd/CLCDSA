import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
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
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.err.println(testNumber);
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		char[][] map = IOUtils.readTable(in, rowCount, columnCount);
		int count = 0;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (Character.isDigit(map[i][j]))
					count = Math.max(count, map[i][j] - '0' + 1);
			}
		}
		int[] answer = new int[count];
		boolean[] lucky = new boolean[count];
		for (int i = 0; i < count; i++) {
			int row = -1;
			int column = -1;
			for (int j = 0; j < rowCount; j++) {
				for (int k = 0; k < columnCount; k++) {
					if (map[j][k] == '0' + i) {
						row = j;
						column = k;
					}
				}
			}
			Queue<Pair<Integer, Integer>> queue = new ArrayDeque<Pair<Integer, Integer>>();
			Set<Pair<Integer, Integer>> visited = new HashSet<Pair<Integer, Integer>>();
			Pair<Integer, Integer> start = Pair.makePair(row, column);
			queue.add(start);
			visited.add(start);
			while (!queue.isEmpty()) {
				row = queue.peek().first;
				column = queue.poll().second;
				for (int j = 1; j < 4; j++) {
					int newRow = row + MiscUtils.DX4[j];
					int newColumn = column + MiscUtils.DY4[j];
					Pair<Integer, Integer> next = null;
					if (map[newRow][newColumn] != '#' && !visited.contains(next = Pair.makePair(newRow, newColumn))) {
						queue.add(next);
						visited.add(next);
					}
				}
			}
			Set<Set<Pair<Integer, Integer>>> set = new HashSet<Set<Pair<Integer, Integer>>>();
			Queue<Set<Pair<Integer, Integer>>> setQueue = new ArrayDeque<Set<Pair<Integer, Integer>>>();
			set.add(visited);
			setQueue.add(visited);
			answer[i] = visited.size();
			if (visited.size() == 1)
				lucky[i] = true;
			while (!setQueue.isEmpty()) {
				Set<Pair<Integer, Integer>> current = setQueue.poll();
				for (int j = 0; j < 4; j++) {
					if (j == 2)
						continue;
					Set<Pair<Integer, Integer>> next = new HashSet<Pair<Integer, Integer>>();
					for (Pair<Integer, Integer> pair : current) {
						int newRow = pair.first + MiscUtils.DX4[j];
						int newColumn = pair.second + MiscUtils.DY4[j];
						Pair<Integer, Integer> newPair;
						if (map[newRow][newColumn] != '#')
							newPair = Pair.makePair(newRow, newColumn);
						else
							newPair = pair;
						if (!visited.contains(newPair)) {
							next = null;
							break;
						}
						next.add(newPair);
					}
					if (next == null || set.contains(next))
						continue;
					if (next.size() == 1) {
						lucky[i] = true;
						break;
					}
					set.add(next);
					setQueue.add(next);
				}
				if (lucky[i])
					break;
			}
		}
		out.printLine("Case #" + testNumber + ":");
		for (int i = 0; i < count; i++)
			out.printLine(i + ":", answer[i], lucky[i] ? "Lucky" : "Unlucky");
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
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

