import java.io.OutputStreamWriter;
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
import java.io.FileInputStream;
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
	private int total;
	private int activities;
	private double[] all;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.err.println(testNumber);
		int count = in.readInt();
		activities = in.readInt();
		Rational[] probability = new Rational[count];
		int[] max = new int[count];
		for (int i = 0; i < count; i++) {
			String p = in.readString();
			max[i] = in.readInt();
			String[] tokens = p.split("/");
			probability[i] = new Rational(Long.parseLong(tokens[0]), Long.parseLong(tokens[1]));
		}
		total = (int) ArrayUtils.sumArray(max);
		all = new double[total];
		int index = 0;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < max[i]; j++)
				all[index++] = probability[i].value();
		}
		Arrays.sort(all);
		double answer = 1;
		double[] gammas = new double[activities + 1];
		int left = 0;
		int right = activities;
		while (right - left > 4) {
			int midLeft = (2 * left + right) / 3;
			int midRight = (2 * right + left) / 3;
			if (calculate(midLeft) > calculate(midRight))
				left = midLeft;
			else
				right = midRight;
		}
		for (int i = left; i <= right; i++) {
			double gamma = calculate(i);
			answer = Math.min(answer, gamma);
		}
		out.printLine("Case #" + testNumber + ":", answer);
	}

	private double calculate(int i) {
		double alpha = 1;
		double beta = 0;
		double gamma = 0;
		for (int j = 0; j < i; j++) {
			double p = all[total - j - 1];
			gamma += beta * p;
			beta = (alpha + beta) * (1 - p);
			alpha *= p;
		}
		for (int j = total - (activities - i); j < total; j++) {
			double p = all[total - j - 1];
			gamma += beta * p;
			beta = (alpha + beta) * (1 - p);
			alpha *= p;
		}
		return gamma;
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

class Rational implements Comparable<Rational> {

	public final long numerator;
	public final long denominator;

	public Rational(long numerator, long denominator) {
		if (denominator == 0)
			throw new IllegalArgumentException();
		long gcd = IntegerUtils.gcd(Math.abs(numerator), Math.abs(denominator));
		if (denominator > 0) {
			this.numerator = numerator / gcd;
			this.denominator = denominator / gcd;
		} else {
			this.numerator = -numerator / gcd;
			this.denominator = -denominator / gcd;
		}
	}

	public String toString() {
		return numerator + "/" + denominator;
	}

	public int compareTo(Rational other) {
		return IntegerUtils.longCompare(numerator * other.denominator, denominator * other.numerator);
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Rational rational = (Rational) o;

		if (denominator != rational.denominator) return false;
		if (numerator != rational.numerator) return false;

		return true;
	}

	public int hashCode() {
		int result = (int) (numerator ^ (numerator >>> 32));
		result = 31 * result + (int) (denominator ^ (denominator >>> 32));
		return result;
	}

	public double value() {
		return (double)numerator / denominator;
	}
}

class ArrayUtils {

	public static long sumArray(int[] array) {
		long result = 0;
		for (int element : array)
			result += element;
		return result;
	}

	}

class IntegerUtils {
	public static long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

    public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}

