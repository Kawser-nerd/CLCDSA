import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ogiekako
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "D-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        int init = 0;
        String s = in.next();
        int N = s.length();
        for (int i = 0; i < N; i++) if (s.charAt(i) == 'X') init |= 1 << i;
        double[] dp = new double[1 << N];
        for (int i = (1<<N)-2; i>=0; i--) {
            double sum = 0;
            for (int j = 0; j < N; j++) {
                int k = j;
                while (i << 31 - k % N < 0) k++;
                sum += N - (k - j) + dp[(i | (1 << (k % N)))];
            }
            dp[i] = sum / N;
//            debug(Integer.toBinaryString(i), dp[i]);
        }
        out.printFormat("Case #%d: %.12f\n", testNumber, dp[init]);
    }
    }

class MyScanner {
    private final InputStream in;

    public MyScanner(InputStream in) {
        this.in = in;
    }

    int bufLen;
    int bufPtr;
    byte[] buf = new byte[1024];

    public int read() {
        if (bufLen == -1)
            throw new InputMismatchException();
        if (bufPtr >= bufLen) {
            bufPtr = 0;
            try {
                bufLen = in.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (bufLen <= 0)
                return -1;
        }
        return buf[bufPtr++];
    }

    private char[] strBuf = new char[65536];

    public String next() {
        int strLen = 0;
        int c;
        do {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        } while (Character.isWhitespace(c));
        do {
            if (strLen + 1 >= strBuf.length) {
                char[] tmp = new char[strBuf.length * 2];
                System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                strBuf = tmp;
            }
            strBuf[strLen++] = (char) c;
            c = read();
        } while (c != -1 && !Character.isWhitespace(c));
        return new String(strBuf, 0, strLen);
    }


    }

class MyPrintWriter {
    PrintWriter out;

    public MyPrintWriter(OutputStream outputStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public MyPrintWriter(Writer writer) {
        out = new PrintWriter(writer);
    }

    public void close() {
        out.close();
    }

    public void printFormat(String format, Object... args) {
        out.printf(format, args);
    }

}

