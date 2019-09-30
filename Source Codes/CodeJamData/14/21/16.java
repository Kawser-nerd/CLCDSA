import java.util.stream.IntStream;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.math.BigDecimal;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.function.IntPredicate;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Jacob Jiang
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
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

    private int n;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        char[][] str = in.next2DCharArray(n);
        //noinspection unchecked
        List<Pair<Character, Integer>>[] lists = new List[n];
        for (int i = 0; i < n; i++) {
            lists[i] = runCode(str[i]);
        }
        out.print("Case #" + testNumber + ": ");
        for (int i = 1; i < n; i++) {
            if (!equal(lists[0], lists[i])) {
                out.println("Fegla Won");
                return;
            }
        }
//        System.out.println(Arrays.toString(lists));
        int m = lists[0].size();
        int answer = 0;
        for (int j = 0; j < m; j++) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = lists[i].get(j).second;
            }
            Arrays.sort(a);
            for (int i = 0; i < n; i++) {
                answer += Math.abs(a[i] - a[n / 2]);
            }
        }
        out.println(answer);
    }

    private boolean equal(List<Pair<Character, Integer>> list, List<Pair<Character, Integer>> list1) {
        return list.size() == list1.size() && IntStream.range(0, list.size()).allMatch(i -> list.get(i).first == list1.get(i).first);
    }

    private List<Pair<Character, Integer>> runCode(char[] str) {
        List<Pair<Character, Integer>> result = new ArrayList<>();
        int count = 1;
        char c = str[0];
        for (int i = 1; i < str.length; i++) {
            if (c != str[i]) {
                result.add(Pair.makePair(c, count));
                count = 1;
                c = str[i];
            } else {
                count++;
            }
        }
        result.add(Pair.makePair(c, count));
        return result;
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
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

    public int nextInt() {
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
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String next() {
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

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public char[] nextCharArray() {
        return next().toCharArray();
    }

    public char[][] next2DCharArray(int n) {
        char[][] result = new char[n][];
        for (int i = 0; i < n; i++) {
            result[i] = nextCharArray();
        }
        return result;
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void println(int i) {
        writer.println(i);
    }

    public void println(String x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

    public void print(String s) {
        writer.print(s);
    }

}

class Pair<A,B> implements Comparable<Pair<A, B>> {
    public final A first;
    public final B second;

    public Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }

    public static <A, B> Pair<A, B> makePair(A first, B second) {
        return new Pair<A, B>(first, second);
    }

    public int compareTo(Pair<A, B> anotherPair) {
        //noinspection unchecked
        int result = ((Comparable<A>)first).compareTo(anotherPair.first);
        if (result != 0) {
            return result;
        }
        //noinspection unchecked
        return ((Comparable<B>)second).compareTo(anotherPair.second);
    }


    public String toString() {
        return "(" + first + ", " + second + ")";
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) return false;
        if (second != null ? !second.equals(pair.second) : pair.second != null) return false;

        return true;
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }
}

