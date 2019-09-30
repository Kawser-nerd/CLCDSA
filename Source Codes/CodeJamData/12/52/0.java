import java.util.Map;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
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
	int side;
	private Map<Node, Node> mainNode;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.err.println(testNumber);
		out.print("Case #" + testNumber + ": ");
		side = in.readInt();
		mainNode = new HashMap<Node, Node>();
		int count = in.readInt();
		int[] x = new int[count];
		int[] y = new int[count];
		IOUtils.readIntArrays(in, x, y);
		for (int i = 0; i < count; i++) {
			Node node = new Node(x[i], y[i]);
			Node[] main = new Node[6];
			main[0] = get(new Node(x[i] + 1, y[i] + 1));
			main[1] = get(new Node(x[i], y[i] + 1));
			main[2] = get(new Node(x[i] - 1, y[i]));
			main[3] = get(new Node(x[i] - 1, y[i] - 1));
			main[4] = get(new Node(x[i], y[i] - 1));
			main[5] = get(new Node(x[i] + 1, y[i]));
			boolean ring = false;
			for (int j = 0; j < 6; j++) {
				if (main[j] == null)
					continue;
				for (int k = j + 2; k < 6; k++) {
					if (main[j] == main[k] && main[j + 1] != main[j] && main[(k + 1) % 6] != main[k])
						ring = true;
				}
			}
			for (Node current : main) {
				if (current == null)
					continue;
				mainNode.put(current, node);
				node.sideMask |= current.sideMask;
				node.vertexMask |= current.vertexMask;
			}
			mainNode.put(node, node);
			boolean bridge = Integer.bitCount(node.vertexMask) >= 2;
			boolean fork = Integer.bitCount(node.sideMask) >= 3;
			if (!ring && !bridge && !fork)
				continue;
			boolean first = true;
			if (bridge) {
				if (!first)
					out.print('-');
				first = false;
				out.print("bridge");
			}
			if (fork) {
				if (!first)
					out.print('-');
				first = false;
				out.print("fork");
			}
			if (ring) {
				if (!first)
					out.print('-');
				first = false;
				out.print("ring");
			}
			out.printLine(" in move", i + 1);
			return;
		}
		out.printLine("none");
	}

	private Node get(Node node) {
		if (mainNode.get(node) == null)
			return null;
		if (mainNode.get(node) == node)
			return node;
		Node result = get(mainNode.get(node));
		mainNode.put(node, result);
		return result;
	}

	class Node {
		int x, y;
		int sideMask;
		int vertexMask;

		Node(int x, int y) {
			this.x = x;
			this.y = y;
			if (x == 1 && y == 1)
				vertexMask = 1;
			else if (x == 1 && y == side)
				vertexMask = 2;
			else if (x == side && y == 1)
				vertexMask = 4;
			else if (x == 2 * side - 1 && y == side)
				vertexMask = 8;
			else if (x == side && y == 2 * side - 1)
				vertexMask = 16;
			else if (x == 2 * side - 1 && y == 2 * side - 1)
				vertexMask = 32;
			else if (x == 1)
				sideMask = 1;
			else if (y == 1)
				sideMask = 2;
			else if (y - x == side - 1)
				sideMask = 4;
			else if (x - y == side - 1)
				sideMask = 8;
			else if (x == 2 * side - 1)
				sideMask = 16;
			else if (y == 2 * side - 1)
				sideMask = 32;
		}

		public boolean equals(Object o) {
			if (this == o) return true;
			if (!(o instanceof Node)) return false;

			Node node = (Node) o;

			if (x != node.x) return false;
			if (y != node.y) return false;

			return true;
		}

		public int hashCode() {
			int result = x;
			result = 31 * result + y;
			return result;
		}
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

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

