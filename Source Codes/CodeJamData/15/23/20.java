import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
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
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        out.print("Case #" + testNumber + ": ");
        int N = in.nextInt();
        int[] s = new int[500001];
        long[] m = new long[500001];
        int p = 0;
        for (int i = 0; i < N; i++) {
            int D = in.nextInt();
            int NUM = in.nextInt();
            int M = in.nextInt();
            for (int j = 0; j < NUM; j++) {
                s[p] = D;
                m[p] = M+j;
                p++;
            }
        }
        int ans = p;
        for (int i = 0; i < p; i++) {
            //double time = (360-s[i])/360.0 * m[i];
            int encounter = 0;
            for (int j = 0; j < p; j++) {
                if (i == j) continue;
                // time / m[j] * 360 + s[j]
                // (360 - s[i])/360 * m[i] / m[j] * 360 + s[j]
                // (360 - s[i]) * m[i] / m[j] + s[j]
                long rotate = ((360-s[i]) * m[i] + s[j] * m[j]) / (m[j] * 360);
                if (rotate == 0) {
                    encounter++;
                } else if (rotate >= 2) {
                    encounter += Math.min(p+1,rotate)-1;
                }
            }
            ans = Math.min(ans, encounter);
        }
        out.println(ans);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}

