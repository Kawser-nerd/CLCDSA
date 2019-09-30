import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskCStupid solver = new TaskCStupid();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskCStupid {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println("[" + testNumber + "]");
        int n = in.nextInt();
        boolean[] type = new boolean[n];
        int[] id = new int[n];
        int[] all = new int[n];
        int cn = 0;
        for (int i = 0; i < n; i++) {
            type[i] = in.next().equals("E");
            id[i] = in.nextInt() - 1;
            if (id[i] >= 0) {
                all[cn++] = id[i];
            }
        }
        all = Arrays.copyOf(all, cn);
        all = ArrayUtils.sortAndUnique(all);
        for (int i = 0; i < n; i++) {
            if (id[i] >= 0) {
                id[i] = Arrays.binarySearch(all, id[i]);
            }
        }
        cn = all.length;
        boolean[][] dp = new boolean[n + 1][1 << cn];
        for (boolean[] d : dp) {
            Arrays.fill(d, true);
        }
        for (int i = 0; i < n; i++) {
            boolean[][] next = new boolean[n + 1][1 << cn];
            for (int count = 0; count <= n; count++) {
                for (int mask = 0; mask < 1 << cn; mask++) {
                    if (!dp[count][mask]) continue;
                    if (type[i]) {
                        if (id[i] >= 0) {
                            if (((mask >> id[i]) & 1) == 0)
                                next[count][mask | (1 << id[i])] = true;
                        } else {
                            if (count + 1 <= n)
                                next[count + 1][mask] = true;
                            for (int t = 0; t < cn; t++) {
                                if (((mask >> t) & 1) == 0) {
                                    next[count][mask | (1 << t)] = true;
                                }
                            }
                        }
                    } else {
                        if (id[i] >= 0) {
                            if (((mask >> id[i]) & 1) == 1) {
                                next[count][mask & (~(1 << id[i]))] = true;
                            }
                        } else {
                            if (count > 0) {
                                next[count - 1][mask] = true;
                            }
                            for (int t = 0; t < cn; t++) {
                                if (((mask >> t) & 1) == 1) {
                                    next[count][mask & (~(1 << t))] = true;
                                }
                            }
                        }
                    }
                }
            }
            dp = next;
        }
        int ans = Integer.MAX_VALUE;
        for (int count = 0; count <= n; count++)
            for (int mask = 0; mask < 1 << cn; mask++) {
                if (!dp[count][mask]) continue;
                ans = Math.min(ans, count + Integer.bitCount(mask));
            }
        out.println("Case #" + testNumber + ": " + (ans == Integer.MAX_VALUE ? "CRIME TIME" : ans));
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

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

    static public int[] sortAndUnique(int[] a) {
        int[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        int last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
                last = ret[i];
            }
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }


}

