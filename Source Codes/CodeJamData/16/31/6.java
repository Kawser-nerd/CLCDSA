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
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int n = in.nextInt();
        int[] p = in.nextIntArray(n);
        int sum = 0;
        for (int i = 0; i < n; i++) sum += p[i];
        while (true) {
            int m1 = -1, m2 = -1;
            for (int i = 0; i < n; i++) if (p[i] != 0) {
                if (m1 == -1 || p[i] > p[m1]) {
                    if (m2 == -1 || p[i] > p[m2]) m2 = i; else m1 = i;
                }
            }
            if (m1 == -1 && m2 == -1) break;
            if (m1 == -1 || p[m1] != p[m2] || sum == 3) {
                out.print((char)(m2 + 'A') + " ");
                p[m2]--;
                sum--;
            } else {
                out.print("" + (char)(m1 + 'A') + (char)(m2 + 'A') + " ");
                p[m1]--;
                p[m2]--;
                sum -= 2;
            }
            for (int i = 0; i < n; i++) {
                if (p[i] * 2 > sum) out.println("BAD");
            }
        }
        out.println();
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

    public int[] nextIntArray(int n, int offset) {
        int[] res = new int[n + offset];
        for (int i = 0; i < n; i++) res[i + offset] = nextInt();
        return res;
    }
    public int[] nextIntArray(int n) {
        return nextIntArray(n, 0);
    }
}

