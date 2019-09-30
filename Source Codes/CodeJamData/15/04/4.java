import java.io.FileInputStream;
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
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        String ans = "RICHARD";
        int x = in.nextInt();
        int r = in.nextInt();
        int c = in.nextInt();
        if (r < c) {
            int t = r; r = c; c = t;
        }
        if (r * c % x == 0 && x <= r && x <= 2 * c && x < 7) {
            switch (x) {
                case 1:
                case 2:
                case 3:
                    ans = "GABRIEL";
                    break;
                case 4:
                    if (c >= 3) ans = "GABRIEL";
                    break;
                case 5:
                    if (c == 3 && r > 5 || c > 3) ans = "GABRIEL";
                    break;
                case 6:
                    if (c >= 4) ans = "GABRIEL";
                    break;
            }
        }
        out.printf("Case #%d: %s\n", testNumber, ans);
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

}

