import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("a.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		LastWord solver = new LastWord();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class LastWord {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.nextToken();
        String answer = get(s);
        out.println("Case #" + testNumber + ": " + answer);
    }

    String get(String s) {
        int n = s.length();
        StringBuilder result = new StringBuilder();
        int[] prefixMax = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixMax[i + 1] = Math.max(prefixMax[i], s.charAt(i));
        }
        boolean[] used = new boolean[n];
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == prefixMax[i + 1]) {
                result.append(s.charAt(i));
                used[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                result.append(s.charAt(i));
            }
        }
        return result.toString();
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

}

