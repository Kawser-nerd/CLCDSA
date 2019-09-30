import java.io.StreamTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Reader;
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
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(@SuppressWarnings("UnusedParameters") int testNumber, TokenizerReader in, PrintWriter out) {
        int n = in.nextInt();
        String[] fingerprint = new String[n];
        ArrayList<Integer>[] repetitions = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            char[] s = in.nextString().toCharArray();
            char last = 'a'-1;
            int cur = 0;
            repetitions[i] = new ArrayList<>();
            StringBuilder sb = new StringBuilder();
            for (char c : s) {
                if (c == last)
                    cur++;
                else {
                    if (last >= 'a')
                        repetitions[i].add(cur);
                    cur = 1;
                    last = c;
                    sb.append(last);
                }
            }
            repetitions[i].add(cur);
            fingerprint[i] = sb.toString();
        }

        out.print("Case #" + testNumber + ": ");

        for (int i = 1; i < n; ++i)
            if (!fingerprint[i].equals(fingerprint[0])) {
                out.println("Fegla Won");
                return;
            }

        int m = repetitions[0].size();
        int res = 0;
        for (int j = 0; j < m; ++j) {
            int[] cnt = new int[n];
            for (int i = 0; i < n; ++i)
                cnt[i] = repetitions[i].get(j);
            res += solve(cnt);
        }
        out.println(res);
    }

    private int solve(int[] cnt) {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i <= 100; ++i) {
            int cur = 0;
            for (int c : cnt)
                cur += Math.abs(c - i);
            res = Math.min(res, cur);
        }
        return res;
    }
}

class TokenizerReader extends StreamTokenizer {
    public TokenizerReader(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        defaultConfig();
    }

    public String nextString() {
        try {
            nextToken();
        } catch (IOException e) {
            throw new RuntimeException("nextString: exception in line " + lineno(), e);
        }
        return sval;
    }

    public String next() {
        return nextString();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public void defaultConfig() {
        resetSyntax();
        wordChars(33, 126);
        whitespaceChars(0, ' ');
    }

}

