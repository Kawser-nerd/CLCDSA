import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.Reader;
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
			inputStream = new FileInputStream("taskc1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskc1.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC1 solver = new TaskC1();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC1 {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        out.print("Case #" + testNumber + ": ");
        System.err.println("[" + testNumber + "]");
        int n = in.nextInt();
        int m = in.nextInt();
        int p = in.nextInt();
        int[] from = new int[m];
        int[] to = new int[m];
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        int[] path = new int[p];
        for (int i = 0; i < p; i++) {
            path[i] = in.nextInt() - 1;
        }
        int[] pathV = new int[p + 1];
        pathV[0] = 0;
        for (int i = 0; i < p; i++) {
            pathV[i + 1] = to[path[i]];
        }
        boolean[] was = new boolean[n];
        int ans = -1;
        for (int bad = 0; bad < p; bad++) {
            if (was[pathV[bad + 1]] || pathV[bad + 1] == pathV[bad]) {
                ans = bad;
                break;
            }
            List<Integer> edgesLeft = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                if (was[from[i]] || was[to[i]] || from[i] == to[i]) continue;
                edgesLeft.add(i);
            }
            int[][] dist = new int[n][n];
            boolean ok = false;
            for (int mask = 0; mask < 1 << edgesLeft.size(); mask++) {
                for (int[] d : dist) {
                    Arrays.fill(d, Integer.MAX_VALUE);
                }
                for (int i = 0; i < n; i++) dist[i][i] = 0;
                for (int i1 = 0; i1 < edgesLeft.size(); i1++) {
                    int i = edgesLeft.get(i1);
                    dist[from[i]][to[i]] = Math.min(dist[from[i]][to[i]], ((mask >> i1) & 1) == 0 ? a[i] : b[i]);
                }
                for (int i = 0; i < m; i++) {
                    if (was[from[i]] || was[to[i]]) {
                        dist[from[i]][to[i]] = Math.min(dist[from[i]][to[i]], b[i]);
                    }
                }
                for (int i = 0; i < bad; i++) {
                    dist[pathV[i]][pathV[i + 1]] = Math.min(dist[pathV[i]][pathV[i + 1]], a[path[i]]);
                }
                for (int k = 0; k < n; k++) {
                    int[] distk = dist[k];
                    for (int i = 0; i < n; i++) {
                        int[] disti = dist[i];
                        for (int j = 0; j < n; j++) {
                            if (disti[k] == Integer.MAX_VALUE || distk[j] == Integer.MAX_VALUE) {
                                continue;
                            }
                            disti[j] = Math.min(disti[j], disti[k] + distk[j]);
                        }
                    }
                }
                boolean cur = true;
                for (int i = 0; i <= bad; i++) {
                    if (dist[pathV[i]][1] < a[path[i]] + dist[pathV[i + 1]][1]) {
                        cur = false;
                        break;
                    }
                }
                if (cur) {
                    ok = true;
                    break;
                }
//                if (dist[pathV[bad]][1] >= a[path[bad]] + dist[pathV[bad + 1]][1]) {
//                    ok = true;
//                    break;
//                }
            }
            if (!ok) {
                ans = bad;
                break;
            }
            was[pathV[bad]] = true;
        }
        out.println(ans < 0 ? "Looks Good To Me" : (path[ans] + 1));
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

