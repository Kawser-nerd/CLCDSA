import java.io.FileInputStream;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Random;
import java.io.FilenameFilter;
import java.util.Locale;
import java.util.Scanner;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

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
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    double count(double[] p) {
        int n = p.length;
        double[][] a = new double[n + 1][n + 1];
        a[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i + 1][j + 1] += p[i] * a[i][j];
                a[i + 1][j] += (1 - p[i]) * a[i][j];
            }
        }
        return a[n][n / 2];
    }

    double solveGreedy(double[] p, int k) {
        Arrays.sort(p);
        double[] q = new double[k];
        double best = 0;
        for (int t = 0; t <= k; t++) {
            for (int i = 0; i < t; i++) {
                q[i] = p[i];
            }
            for (int i = 0; i < k - t; i++) {
                q[i + t] = p[p.length - 1 - i];
            }
            double v = count(q);
            if (v > best) {
                best = v;
            }
        }
        return best;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
int n = in.nextInt();
        int k = in.nextInt();
        double[] p = new double[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextDouble();
        }
        double v = solveGreedy(p, k);
        out.printf("Case #%d: %.20f\n", testNumber, v);
    }
}

