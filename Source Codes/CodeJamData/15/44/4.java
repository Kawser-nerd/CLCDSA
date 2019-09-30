import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.List;
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
		DrumDecoratorHard solver = new DrumDecoratorHard();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class DrumDecoratorHard {
    static final int MOD = 1000000007;

    static int get(int r, int c) {
        int[] f = new int[r + 1];
        int[] g = new int[r + 1];
        f[0] = 1;
        g[0] = 1;
        for (int i = 1; i <= r; i++) {
            if (i > 1) {
                g[i] = f[i - 2];
            }
            f[i] = g[i - 1];
            if (c % 3 == 0 && i > 1) {
                f[i] = (int) ((f[i] + 3L * g[i - 2]) % MOD);
            }
            if (c % 6 == 0 && i > 1) {
                f[i] = (int) ((f[i] + 6L * g[i - 2]) % MOD);
            }
            if (c % 4 == 0 && i > 2) {
                f[i] = (int) ((f[i] + 4L * g[i - 3]) % MOD);
            }
        }
        return (f[r] + g[r]) % MOD;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int r = in.nextInt();
        int c = in.nextInt();
        int ans = 0;
        for (int i = 1; i <= c; i++) {
            int cycle = MathUtils.gcd(i, c);
            ans = (ans + get(r, cycle)) % MOD;
        }
        ans = (int) ((long) ans * MathUtils.modPow(c, MOD - 2, MOD) % MOD);
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

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}

class MathUtils {

    public static int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }


    public static int modPow(int a, int b, int mod) {
        int ret = 1;
        a = (a % mod + mod) % mod;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret = (int) ((long) ret * a % mod);
            }
            a = (int) ((long) a * a % mod);
            b >>= 1;
        }
        return ret % mod;
    }

}

