import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.math.BigInteger;
import java.io.FilenameFilter;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();
        List<int[]> la = generate(a);
        List<int[]> lb = generate(b);
        List<int[]> lk = generate(k);
        long answer = 0;
        for (int[] ia : la) {
            for (int[] ib : lb) {
                for (int[] ik : lk) {
                    long result = 1;
                    for (int i = 0; i < 31; i++) {
                        result *= get(ia[i], ib[i], ik[i]);
                    }
                    answer += result;
                }
            }
        }
        out.print("Case #" + testNumber + ": ");
        out.println(answer);
    }

    private long get(int a, int b, int k) {
        if (k == -1) {
            int result = 1;
            if (a == -1)
                result *= 2;
            if (b == -1)
                result *= 2;
            return result;
        }
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        if (a >= 0) {
            return (a & b) == k ? 1 : 0;
        }
        if (b == -1) {
            return k == 0 ? 3 : 1;
        }
        if (b == 1) {
            return 1;
        }
        return k == 0 ? 2 : 0;
    }

    private List<int[]> generate(int n) {
        int[] binary = new int[32];
        for (int i = 0; i < 31; i++) {
            binary[i] = ((n & (1 << i)) != 0) ? 1 : 0;
        }
        List<int[]> result = new ArrayList<>();
        for (int i = 31; i >= 0; i--) {
            if (binary[i] == 1) {
                int[] cur = binary.clone();
                cur[i] = 0;
                for (int j = 0; j < i; j++) {
                    cur[j] = -1;
                }
                result.add(cur);
            }
        }
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

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void println(long x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

    public void print(String s) {
        writer.print(s);
    }

}

