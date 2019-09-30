import java.io.FileInputStream;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int b = in.nextInt();
        long m = in.nextLong();
        long max = 1L << (b - 2L);
        if (m > max) {
            out.println("IMPOSSIBLE");
        } else {
            int[][] ans = new int[b][b];
            for (int i = 0; i < b - 1; i++) {
                ans[i][i + 1] = 1;
            }
            m--;
            for (int bb = b - 3; bb >= 0; bb--) {
                for (int ee = bb + 2; ee < b; ee++) {
                    long q = 1L << ((long)(Math.max(b - ee, 2) - 2));
                    if (m >= q) {
                        ans[bb][ee] = 1;
                        m -= q;
                    }
                }
            }
            out.println("POSSIBLE");
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    out.print(ans[i][j]);
                }
                out.println();
            }
        }
    }
}

class Reader {
    private BufferedReader in;
    private StringTokenizer st;
    public Reader(InputStream is) {
        in = new BufferedReader(new InputStreamReader(is));
    }
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(in.readLine());
            }
            return st.nextToken();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
    public long nextLong() {
        return Long.parseLong(next());
    }

}

