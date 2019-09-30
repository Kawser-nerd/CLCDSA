import java.io.Reader;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		SmoothingWindow solver = new SmoothingWindow();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class SmoothingWindow {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println(testNumber);
        int n = in.nextInt();
        int k = in.nextInt();
        int maximal = 0;
        int[] a = in.readIntArray(n - k + 1);
        for (int i : a) {
            maximal = Math.max(maximal, Math.abs(i));
        }
        int[] dif = new int[n];
        for (int i = k; i < n; i++) {
            dif[i] = (a[i - k + 1] - a[i - k]) + dif[i - k];
        }
        int[] left = new int[k];
        int[] right = new int[k];
        long z = a[0];
        for (int i = 0; i < n; i++) {
            left[i % k] = Math.min(left[i % k], dif[i]);
            right[i % k] = Math.max(right[i % k], dif[i]);
        }
        for (int i = 0; i < k; i++) z += left[i];
        long ans = Long.MAX_VALUE;
        for (long x = z / k - 10000; ; x++) {
            long minSum = 0;
            for (int i = 0; i < k; i++) {
                minSum += x - left[i];
            }
            long neededSum = a[0];
            if (neededSum < minSum) {
                break;
            }
            neededSum -= minSum;
            long l = -1;
            long r = Integer.MAX_VALUE;
            while (l < r - 1) {
                long mid = (l + r) >> 1;
                long leftSum = neededSum;
                for (int i = 0; i < k; i++) {
                    if (mid < right[i] - left[i]) {
                        leftSum = 1;
                        break;
                    }
                    long can = mid - (right[i] - left[i]);
                    can = Math.min(can, leftSum);
                    leftSum -= can;
                }
                if (leftSum == 0) r = mid; else l = mid;
            }
            ans = Math.min(ans, r);
        }
        out.println("Case #" + testNumber + ": " + ans);
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

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}

