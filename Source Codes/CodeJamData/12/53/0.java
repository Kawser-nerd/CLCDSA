import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.SortedSet;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
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
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		long money = in.readLong();
		long fee = in.readLong();
		int count = in.readInt();
		long[] price = new long[count];
		long[] stale = new long[count];
		IOUtils.readLongArrays(in, price, stale);
		long currentDeliveryCost = fee;
		long lastStale = -1;
		long[] antiStale = stale.clone();
		for (int i = 0; i < count; i++)
			antiStale[i] = -antiStale[i];
		Integer[] order = ListUtils.order(Array.wrap(price), Array.wrap(antiStale));
		long answer = 0;
		for (int i : order) {
			if (lastStale >= stale[i])
				continue;
			long p1 = currentDeliveryCost;
			long p2 = price[i];
			long q = stale[i] - lastStale;
			long c = lastStale + 1;
			if (p1 / p2 >= c) {
				if (money / q >= price[i]) {
					long alpha1 = money / (currentDeliveryCost + q * price[i]);
					long beta1 = q * alpha1;
					if (alpha1 * p1 + beta1 * p2 > money)
						throw new RuntimeException();
					if (beta1 > q * alpha1)
						throw new RuntimeException();
					answer = Math.max(answer, c * alpha1 + beta1);
					long alpha2 = alpha1 + 1;
					if (alpha2 * currentDeliveryCost <= money) {
						long remainingMoney = money - alpha2 * p1;
						long beta2 = remainingMoney / p2;
						if (alpha2 * p1 + beta2 * p2 > money)
							throw new RuntimeException();
						if (beta2 > q * alpha2)
							throw new RuntimeException();
						answer = Math.max(answer, c * alpha2 + beta2);
					}
				} else {
					long alpha = 1;
					long beta = (money - currentDeliveryCost) / p2;
					if (alpha * p1 + beta * p2 > money)
						throw new RuntimeException();
					if (beta > q * alpha)
						throw new RuntimeException();
					answer = Math.max(answer, c * alpha + beta);
				}
			} else {
				long alpha = money / p1;
				long remainingMoney = money - alpha * p1;
				long beta = remainingMoney / p2;
				if (remainingMoney / q >= alpha)
					beta = Math.min(beta, alpha * q);
				if (alpha * p1 + beta * p2 > money)
					throw new RuntimeException();
				if (beta > q * alpha)
					throw new RuntimeException();
				answer = Math.max(answer, c * alpha + beta);
			}
			if (money / price[i] >= stale[i] - lastStale) {
				currentDeliveryCost += (stale[i] - lastStale) * price[i];
				lastStale = stale[i];
			} else
				break;
			if (currentDeliveryCost > money)
				break;
		}
		out.printLine("Case #" + testNumber + ":", answer);
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

	public static void readLongArrays(InputReader in, long[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readLong();
		}
	}

	}

class ListUtils {

	public static Integer[] order(final List<? extends Comparable<?>>...sequences) {
		return ArrayUtils.order(sequences[0].size(), new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				for (List<? extends Comparable> sequence : sequences) {
					//noinspection unchecked
					int value = sequence.get(o1).compareTo(sequence.get(o2));
					if (value != 0)
						return value;
				}
				return 0;
			}
		});
	}

	}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {

	public static List<Long> wrap(long...array) {
		return new LongArray(array);
	}

	protected static class LongArray extends Array<Long> {
		protected final long[] array;

		protected LongArray(long[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Long get(int index) {
			return array[index];
		}

		public Long set(int index, Long value) {
			long result = array[index];
			array[index] = value;
			return result;
		}
	}

	}

class ArrayUtils {
	public static Integer[] generateOrder(int size) {
		Integer[] order = new Integer[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static Integer[] order(int size, Comparator<Integer> comparator) {
		Integer[] order = generateOrder(size);
		Arrays.sort(order, comparator);
		return order;
	}

	}

