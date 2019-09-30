import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.io.File;
import java.util.AbstractList;
import java.util.AbstractCollection;
import java.io.Writer;
import java.util.LinkedList;
import java.io.FilenameFilter;
import java.util.List;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Collections;
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
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    private int cityCount;
    private boolean[][] connect;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
//        System.out.println("testNumber = " + testNumber);
        cityCount = in.nextInt();
        int flightCount = in.nextInt();
        String[] zipCode = in.nextStringArray(cityCount);
        connect = new boolean[cityCount][cityCount];
        for (int i = 0; i < flightCount; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            connect[a][b] = connect[b][a] = true;
        }
        String answer = "zzz";
        int[] order = PermutationUtils.originPermutation(cityCount);
        do {
            if (can(order)) {
                StringBuilder result = new StringBuilder();
                for (int i : order) {
                    result.append(zipCode[i]);
                }
                answer = NumberUtils.min(answer, result.toString());
            }
        } while (PermutationUtils.nextPermutation(order));
        out.print("Case #" + testNumber + ": ");
        out.println(answer);
    }

    private boolean can(int[] order) {
//        System.out.println("order = " + Arrays.toString(order));
        LinkedList<Integer> stack = new LinkedList<>();
        stack.push(order[0]);
        for (int i = 1; i < cityCount; i++) {
            int item = order[i];
            while (!stack.isEmpty() && !connect[stack.peek()][item]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                return false;
            }
            stack.push(item);
//            System.out.println("stack = " + stack);
        }
        return true;
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

    public String[] nextStringArray(int count) {
        String[] result = new String[count];
        for (int i = 0; i < count; i++) {
            result[i] = next();
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

class PermutationUtils {
    public static boolean nextPermutation(int[] permutation) {
        int position = -1;
        for (int i = permutation.length - 2; i >= 0; i--) {
            if (permutation[i] < permutation[i + 1]) {
                position = i;
                break;
            }
        }
        if (position == -1) {
            return false;
        }
        int newPosition = -1;
        for (int i = permutation.length - 1; i >= 0; i--) {
            if (permutation[i] > permutation[position]) {
                newPosition = i;
                break;
            }
        }
        // swap variables
        {
            int swapTempValue = permutation[position];
            permutation[position] = permutation[newPosition];
            permutation[newPosition] = swapTempValue;
        }
        int a = position + 1, b = permutation.length - 1;
        while (a < b) {
            // swap variables
            {
                int swapTempValue = permutation[a];
                permutation[a] = permutation[b];
                permutation[b] = swapTempValue;
            }
            a++;
            b--;
        }
        return true;
    }

    public static int[] originPermutation(int size) {
        int[] result = new int[size];
        for (int i = 0; i < size; i++) {
            result[i] = i;
        }
        return result;
    }

}

class NumberUtils {

    public static <T extends Comparable<T>> T min(T a, T b) {
        return a.compareTo(b) <= 0 ? a : b;
    }

}

