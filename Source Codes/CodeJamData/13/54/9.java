import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("taskd1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskd1.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD1 solver = new TaskD1();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD1 {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        out.print("Case #" + testNumber + ": ");
        System.err.println("[" + testNumber + "]");
        char[] c = in.next().toCharArray();
        int n = c.length;
        double[] dp = new double[1 << n];
        for (int i = (1 << n) - 1; i >= 0; i--) {
            double all = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 0) {
                    double cur = 0;
                    cur += n;
                    int k = j - 1;
                    if (k < 0) k += n;
                    int cost = n - 1;
                    int count = 1;
                    while (((i >> k) & 1) == 1) {
                        cur += cost;
                        ++count;
                        --cost;
                        k--;
                        if (k < 0) k += n;
                    }
                    all += (cur + count * dp[i | (1 << j)]);
                }
            }
            dp[i] = all / n;
        }
        int mask = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == 'X') {
                mask |= 1 << i;
            }
        }
        out.println(dp[mask]);
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

