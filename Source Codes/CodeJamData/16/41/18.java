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
    String ex(String s, int n) {
        if (n == 0) {
            return s;
        }
        switch (s.charAt(0)) {
            case 'P': {
                String p1 = ex("P", n - 1);
                String r1 = ex("R", n - 1);
                if (p1.compareTo(r1) < 0) {
                    return p1 + r1;
                } else {
                    return r1 + p1;
                }
            }
            case 'R': {
                String p1 = ex("R", n - 1);
                String r1 = ex("S", n - 1);
                if (p1.compareTo(r1) < 0) {
                    return p1 + r1;
                } else {
                    return r1 + p1;
                }
            }
            case 'S': {
                String p1 = ex("P", n - 1);
                String r1 = ex("S", n - 1);
                if (p1.compareTo(r1) < 0) {
                    return p1 + r1;
                } else {
                    return r1 + p1;
                }
            }
        }
        return "!";
    }

    int[] cnt(String s) {
        int[] v = new int[3];
        for (int i = 0; i < s.length(); i++) {
            v[S.indexOf(s.charAt(i))]++;
        }
        return v;
    }

    String S = "RPS";

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] v = new int[3];
        for (int i = 0; i < 3; i++) {
            v[i] = in.nextInt();
        }

        String best = "Z";
        for (int s = 0; s < 3; s++) {
            String z = ex("" + S.charAt(s), n);
            int[] w = cnt(z);
            if (Arrays.equals(w, v)) {
                if (z.compareTo(best) < 0) {
                    best = z;
                }
            }
        }
        if (best.equals("Z")) {
            out.printf("Case #%d: IMPOSSIBLE\n", testNumber);
        } else {
            out.printf("Case #%d: %s\n", testNumber, best);
        }
    }
}

