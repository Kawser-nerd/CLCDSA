import java.io.FileInputStream;
import java.util.Arrays;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.util.Scanner;
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
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    final static int MAX = 1000000;
    int[] d;

    public TaskA() {
        d = new int[MAX + 1];
        Arrays.fill(d, -1);
        d[1] = 1;
        int[] q = new int[MAX + 1];
        int h = 0;
        int t = 1;
        q[h] = 1;
        while (h < t) {
            int v = q[h++];
            if (v + 1 <= MAX && d[v + 1] == -1) {
                d[v + 1] = d[v] + 1;
                q[t++] = v + 1;
            }
            int u = reverse(v);
            if (u <= MAX && d[u] == -1) {
                d[u] = d[v] + 1;
                q[t++] = u;
            }
        }
    }

    int reverse(int x) {
        int r = 0;
        while (x != 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();

        out.println("Case #" + testNumber + ": " + d[n]);
    }
}

