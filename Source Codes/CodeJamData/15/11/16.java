import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author AlexFetisov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] m = Utils.readIntArray(in, n);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (m[i-1] > m[i]) {
                res += m[i-1] - m[i];
            }
        }
        out.print("Case #" + testNumber + ": " + res + " ");

        res = Integer.MAX_VALUE;
        for (int rate = 0; rate <= 100000; ++rate) {
            res = Math.min(res, test(n, m, rate));
        }
        out.println(res);
    }

    private int test(int n, int[] m, int rate) {
        int eaten = 0;
        for (int i = 1; i < n; ++i) {
            int was = m[i-1];
            int cur = m[i];
            if (was < rate) {
                eaten += was;
                was = 0;
            } else {
                was -= rate;
                eaten += rate;
            }
            if (was > cur) {
                return Integer.MAX_VALUE;
            }
        }
        return eaten;
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }
}

class Utils {
    public static int[] readIntArray(InputReader in, int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        return a;
    }

}

