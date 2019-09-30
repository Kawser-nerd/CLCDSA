import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileInputStream;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    int[] p;
    int[] q;
    boolean[] pu;
    boolean[] qu;
    int n;

    boolean isOk2(boolean[][] b, int v) {
        if (v == n) {
            return true;
        }
        boolean has = false;
        for (int i = 0; i < n; i++) {
            if (!qu[i] && b[p[v]][i]) {
                has = true;
                qu[i] = true;
                if (!isOk2(b, v + 1)) {
                    return false;
                }
                qu[i] = false;
            }
        }
        return has;
    }

    boolean isOk(boolean[][] b, int v) {
        if (v == n) {
            return isOk2(b, 0);
        }
        for (int i = 0; i < n; i++) {
            if (!pu[i]) {
                p[v] = i;
                pu[i] = true;
                if (!isOk(b, v + 1)) {
                    return false;
                }
                pu[i] = false;
            }
        }
        return true;
    }

    boolean isOk(boolean[][] b) {
        n = b.length;
        p = new int[n];
        q = new int[n];
        pu = new boolean[n];
        qu = new boolean[n];
        return isOk(b, 0);
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        boolean[][] a = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j) == '1';
            }
        }

        boolean[][] b = new boolean[n][n];
        int best = n * n;
        for (int mask = 0; mask < (1 << (n * n)); mask++) {
            int cnt = 0;
            boolean good = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int k = i * n + j;
                    b[i][j] = ((mask & (1 << k)) != 0);
                    if (a[i][j] && !b[i][j]) {
                        good = false;
                    }
                    if (b[i][j] && !a[i][j]) {
                        cnt++;
                    }
                }
            }
            if (good && cnt < best && isOk(b)) {
                best = cnt;
            }
        }
        out.println("Case #" + testNumber + ": " + best);
    }
}

