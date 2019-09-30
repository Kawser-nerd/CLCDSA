import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Collection;
import java.io.InputStream;

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
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println("[" + testNumber + "]");
        int p = in.nextInt();
        int q = in.nextInt();
        int n = in.nextInt();
        int[] h = new int[n];
        int[] g = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = in.nextInt();
            g[i] = in.nextInt();
        }
        Map<Integer, Integer> dp = new HashMap<>();
        dp.put(1, 0);
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> next = new HashMap<>();
            int bDiana = -((h[i] + p - 1) / p);
            for (int take = 0; h[i] > take * p; take++) {
                int left = (h[i] - take * p);
                if ((left - 1) % q > p - 1) continue;
                int d = (left - 1) / q - take - 1;
                bDiana = Math.max(bDiana, d);
            }
            int bNothing = (h[i] + q - 1) / q;
            for (Integer j : dp.keySet()) {
                Integer val = dp.get(j);
                if (j + bNothing >= 0) {
                    putMax(next, j + bNothing, val);
                }
                if (j + bDiana >= 0) {
                    putMax(next, j + bDiana, g[i] + val);
                }
            }
            dp = next;
        }
        int ans = Integer.MIN_VALUE;
        for (int i : dp.values()) ans = Math.max(ans, i);
        out.println("Case #" + testNumber + ": " + ans);
    }

    static <K> void putMax(Map<K, Integer> map, K k, Integer v) {
        Integer was = map.get(k);
        if (was == null) {
            was = v;
        } else {
            was = Math.max(was, v);
        }
        map.put(k, was);
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

    public FastPrinter(Writer out) {
        super(out);
    }


}

