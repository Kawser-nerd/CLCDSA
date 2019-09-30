import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
        int n = in.nextInt();
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = in.nextInt() - 1;
        }
        int[] when = new int[n];
        int answer = 0;
        int[] maxIn = new int[n];
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            Arrays.fill(when, 0);
            when[i] = ++cnt;
            int j;
            for (j = f[i]; when[j] == 0; j = f[j]) {
                when[j] = ++cnt;
            }
            int size = cnt - when[j] + 1;
            if (size == 2) {
                maxIn[j] = Math.max(maxIn[j], when[j] - 1);
            } else {
                answer = Math.max(answer, size);
            }
        }
        int goodDudes = 0;
        int answer2 = 0;
        for (int i = 0; i < n; i++) {
            if (f[f[i]] == i) {
                ++goodDudes;
                answer2 += maxIn[i] + 1;
            }
        }
        answer = Math.max(answer, answer2);
        out.println("Case #" + testNumber + ": " + answer);
    }
}

class InputReader {
    public BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String next() {
        return nextToken();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}

