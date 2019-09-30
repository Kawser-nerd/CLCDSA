import java.io.FileInputStream;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.math.BigDecimal;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

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

    private static long[] tens = new long[16];

    public TaskA() {
        tens[0] = 1;
        for (int i = 1; i < tens.length; i++) {
            tens[i] = tens[i - 1] * 10;
        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long n = in.nextLong();
        long answer = 0;
        for (int i = 0; i < tens.length; i++) {
            if (tens[i] <= n) {
                if (tens[i + 1] <= n) {
                    answer += turn(tens[i], tens[i + 1] - 1);
                } else {
                    answer += turn(tens[i], n);
                }
            }
        }
        out.println("Case #" + testNumber + ": " + answer);
    }

    private long turn(long a, long b) {
        if (a == b)
            return 1;
        return Math.min(turnImpl(a, b), turnImpl(a, b - 1) + 1);
    }

    private long turnImpl(long a, long b) {
        if (a == b)
            return 1;
        String as = String.valueOf(a);
        String bs = String.valueOf(b);
        if (as.length() != bs.length()) {
            throw new RuntimeException();
        }
        long answer = b - a + 1;
        int n = as.length();
        for (int l = 1; l < n; l++) {
            char[] mid = as.toCharArray();
            for (int i = 0; i < l; i++) {
                mid[n - i - 1] = bs.charAt(i);
            }
            long result = Long.parseLong(String.valueOf(mid)) - a + 1;
            StringBuilder builder = new StringBuilder(String.valueOf(mid));
            builder.reverse();
            long mid2 = Long.parseLong(builder.toString());
            if (mid2 > b) {
                continue;
            }
            result += b - mid2 + 1;
            answer = Math.min(answer, result);
        }
        return answer;
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

    public long nextLong() {
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
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public void println(String x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

}

