import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
			final String regex = "B-(small|large).*[.]in";
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
            System.err.println("File = " + toRun);
            inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
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
    final static long mod = 1000*1000*1000 + 7;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        System.err.println("Test " + testNumber + " started");
        System.err.flush();
        out.printFormat("Case #%d: ", testNumber);
        int n = in.readInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.readString();
        }
        for (int i = 0; i < n; i++) {
            if (!isCorrect(s[i])) {
                out.printLine(0);
                return;
            }
        }
        long[] fact = new long[101];
        fact[0] = 1;
        for (int i = 1; i <= 100; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        int[][] totalOccur = new int[26][n];
        int[][] prefixOccur = new int[26][n];
        int[][] suffixOccur = new int[26][n];
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < s[i].length(); j++) {
                    if (s[i].charAt(j) == c) {
                        totalOccur[c - 'a'][i]++;
                    }
                }
                for (int j = 0; j < s[i].length(); j++) {
                    if (s[i].charAt(j) == c) {
                        if (j == 0 || s[i].charAt(j - 1) == c) {
                            prefixOccur[c - 'a'][i]++;
                        } else {
                            break;
                        }
                    }
                }
                for (int j = s[i].length() - 1; j >= 0; j--) {
                    if (s[i].charAt(j) == c) {
                        if (j == s[i].length() - 1 || s[i].charAt(j + 1) == c) {
                            suffixOccur[c - 'a'][i]++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        IntArrayList[] graph = new IntArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new IntArrayList();
        }
        IntArrayList fullChainsLengths = new IntArrayList();
        for (char c = 'a'; c <= 'z'; c++) {
            int fullCnt = 0;
            int prefixCnt = 0;
            int suffixCnt = 0;
            IntArrayList fullChain = new IntArrayList();
            int prefixID = -1;
            int suffixID = -1;
            for (int i = 0; i < n; i++) {
                if (totalOccur[c - 'a'][i] > 0) {
                    if (totalOccur[c - 'a'][i] == s[i].length()) {
                        fullCnt++;
                        fullChain.add(i);
                    } else if (totalOccur[c - 'a'][i] == prefixOccur[c - 'a'][i]) {
                        prefixCnt++;
                        prefixID = i;
                    } else if (totalOccur[c - 'a'][i] == suffixOccur[c - 'a'][i]) {
                        suffixCnt++;
                        suffixID = i;
                    } else {
                        for (int j = 0; j < n; j++) {
                            if (j != i && totalOccur[c - 'a'][j] > 0) {
                                out.printLine(0);
                                return;
                            }
                        }
                    }
                }
            }
            if (prefixCnt > 1 || suffixCnt > 1) {
                out.printLine(0);
                return;
            }
            if (fullCnt > 0) {
                fullChainsLengths.add(fullCnt);
                if (prefixCnt > 0) {
                    addEdge(graph, fullChain.back(), prefixID);
                }
                if (suffixCnt > 0) {
                    addEdge(graph, suffixID, fullChain.get(0));
                }
                for (int j = 1; j < fullChain.size(); j++) {
                    int a = fullChain.get(j - 1);
                    int b = fullChain.get(j);
                    addEdge(graph, a, b);
                }
            } else if (prefixCnt == 1 && suffixCnt == 1) {
                addEdge(graph, suffixID, prefixID);
            }
        }
        IndependentSetSystem dsu = new RecursiveIndependentSetSystem(n);
        for (int a = 0; a < n; a++) {
            for (int i = 0; i < graph[a].size(); i++) {
                int b = graph[a].get(i);
                if (!dsu.join(a, b)) {
                    out.printLine(0);
                    return;
                }
            }
        }
        IntHashSet set = new IntHashSet();
        for (int i = 0; i < n; i++) {
            set.add(dsu.get(i));
        }
        long ans = fact[set.size()];
        for (int i = 0; i < fullChainsLengths.size(); i++) {
            int chainLen = fullChainsLengths.get(i);
            ans = ans * fact[chainLen] % mod;
        }
        out.printLine(ans);
    }

    private void addEdge(IntArrayList[] graph, int a, int b) {
        graph[a].add(b);
    }

    private boolean isCorrect(String s) {
        IntArrayList[] positions = new IntArrayList[26];
        for (int i = 0; i < 26; i++) {
            positions[i] = new IntArrayList();
        }
        for (int i = 0; i < s.length(); i++) {
            positions[s.charAt(i) - 'a'].add(i);
        }
        for (IntArrayList list : positions) {
            for (int i = 1; i < list.size(); i++) {
                int a = list.get(i - 1);
                int b = list.get(i);
                if (a + 1 != b) {
                    return false;
                }
            }
        }
        return true;
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

    public void printLine(long i) {
		writer.println(i);
	}

    public void printLine(int i) {
		writer.println(i);
	}
}

class IntArrayList extends IntList {
	private int[] array;
	private int size;

	public IntArrayList() {
		this(10);
	}

	public IntArrayList(int capacity) {
		array = new int[capacity];
	}

	public IntArrayList(IntList list) {
		this(list.size());
		addAll(list);
	}

	public int get(int index) {
		if (index >= size)
			throw new IndexOutOfBoundsException();
		return array[index];
	}

    public int size() {
		return size;
	}

	public void add(int value) {
		ensureCapacity(size + 1);
		array[size++] = value;
	}

	public void ensureCapacity(int newCapacity) {
		if (newCapacity > array.length) {
			int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
			System.arraycopy(array, 0, newArray, 0, size);
			array = newArray;
		}
	}

}

abstract class IntList extends IntCollection implements Comparable<IntList> {

    public abstract int get(int index);

    public IntIterator iterator() {
		return new IntIterator() {
			private int size = size();
			private int index = 0;

			public int value() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				return get(index);
			}

			public void advance() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				index++;
			}

			public boolean isValid() {
				return index < size;
			}
		};
	}

    public int back() {
		return get(size() - 1);
	}

    public int hashCode() {
		int hashCode = 1;
		for (IntIterator i = iterator(); i.isValid(); i.advance())
			hashCode = 31 * hashCode + i.value();
		return hashCode;
	}

	public boolean equals(Object obj) {
		if (!(obj instanceof IntList))
			return false;
		IntList list = (IntList)obj;
		if (list.size() != size())
			return false;
		IntIterator i = iterator();
		IntIterator j = list.iterator();
		while (i.isValid()) {
			if (i.value() != j.value())
				return false;
			i.advance();
			j.advance();
		}
		return true;
	}

	public int compareTo(IntList o) {
		IntIterator i = iterator();
		IntIterator j = o.iterator();
		while (true) {
			if (i.isValid()) {
				if (j.isValid()) {
					if (i.value() != j.value()) {
						if (i.value() < j.value())
							return -1;
						else
							return 1;
					}
				} else
					return 1;
			} else {
				if (j.isValid())
					return -1;
				else
					return 0;
			}
			i.advance();
			j.advance();
		}
	}

}

interface IndependentSetSystem {
	public boolean join(int first, int second);

	public int get(int index);

    public static interface Listener {
		public void joined(int joinedRoot, int root);
	}
}

class RecursiveIndependentSetSystem implements IndependentSetSystem {
	private final int[] color;
	private final int[] rank;
	private int setCount;
	private Listener listener;

	public RecursiveIndependentSetSystem(int size) {
		color = new int[size];
		rank = new int[size];
		for (int i = 0; i < size; i++)
			color[i] = i;
		setCount = size;
	}

	public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
		color = other.color.clone();
		rank = other.rank.clone();
		setCount = other.setCount;
	}

	public boolean join(int first, int second) {
		first = get(first);
		second = get(second);
		if (first == second)
			return false;
		if (rank[first] < rank[second]) {
			int temp = first;
			first = second;
			second = temp;
		} else if (rank[first] == rank[second])
			rank[first]++;
		setCount--;
		color[second] = first;
		if (listener != null)
			listener.joined(second, first);
		return true;
	}

	public int get(int index) {
		if (color[index] == index)
			return index;
		return color[index] = get(color[index]);
	}

}

class IntHashSet extends IntSet {
	private static final Random RND = new Random();
	private static final int[] SHIFTS = new int[4];
	private static final byte PRESENT_MASK = 1;

    static {
		for (int i = 0; i < 4; i++)
			SHIFTS[i] = RND.nextInt(31) + 1;
	}

	private int size;
	private int[] values;
	private byte[] present;
	private int step;
	private int ratio;

	public IntHashSet() {
		this(3);
	}


	public IntHashSet(int capacity) {
		capacity = Math.max(capacity, 1);
		values = new int[capacity];
		present = new byte[capacity];
		ratio = 2;
		initStep(capacity);
	}

	private void initStep(int capacity) {
		step = RND.nextInt(capacity - 2) + 1;
		while (IntegerUtils.gcd(step, capacity) != 1)
			step++;
	}

	public IntIterator iterator() {
		return new IntIterator() {
			private int position = size == 0 ? values.length : -1;

			public int value() throws NoSuchElementException {
				if (position == -1)
					advance();
				if (position >= values.length)
					throw new NoSuchElementException();
				return values[position];
			}

			public void advance() throws NoSuchElementException {
				if (position >= values.length)
					throw new NoSuchElementException();
				position++;
				while (position < values.length && (present[position] & PRESENT_MASK) == 0)
					position++;
			}

			public boolean isValid() {
				return position < values.length;
			}
		};
	}

	public int size() {
		return size;
	}

	public void add(int value) {
		ensureCapacity((size + 1) * ratio + 2);
		int current = getHash(value);
		while ((present[current] & PRESENT_MASK) != 0) {
			if (values[current] == value)
				return;
			current += step;
			if (current >= values.length)
				current -= values.length;
		}
		present[current] = PRESENT_MASK;
		values[current] = value;
		size++;
	}

	private int getHash(int value) {
		int result = value;
		for (int i : SHIFTS)
			result ^= value >> i;
		result %= values.length;
		if (result < 0)
			result += values.length;
		return result;
	}

	private void ensureCapacity(int capacity) {
		if (values.length < capacity) {
			capacity = Math.max(capacity * 2, values.length);
			rebuild(capacity);
		}
	}

    private void rebuild(int capacity) {
		initStep(capacity);
		int[] oldValues = values;
		byte[] oldPresent = present;
		values = new int[capacity];
		present = new byte[capacity];
		size = 0;
		for (int i = 0; i < oldValues.length; i++) {
			if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK)
				add(oldValues[i]);
		}
	}

}

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();
	public abstract void add(int value);

    public void addAll(IntCollection values) {
		for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
			add(it.value());
		}
	}

}

interface IntIterator {
	public int value() throws NoSuchElementException;
	/*
	 * @throws NoSuchElementException only if iterator already invalid
	 */
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}

abstract class IntSet extends IntCollection {
}

class IntegerUtils {

    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

}

