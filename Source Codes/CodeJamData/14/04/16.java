import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
			inputStream = new FileInputStream("d.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		D solver = new D();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class D {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        double[] naomi = new double[n];
        double[] ken = new double[n];
        for (int i = 0; i < n; i++) {
            naomi[i] = in.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            ken[i] = in.nextDouble();
        }
        Arrays.sort(naomi);
        Arrays.sort(ken);
        int simpleWar = simpleWar(naomi, ken);
        int deceitfulWar = deceitfulWar(naomi, ken);
        out.println("Case #" + testNumber + ": " + deceitfulWar + " " + simpleWar);
    }

    private int simpleWar(double[] naomi, double[] ken) {
        int n = naomi.length;
        int answer = 0;
        int i = n, j = n;
        while (i + j > 0) {
            if (i > 0 && (j == 0 || naomi[i - 1] > ken[j - 1])) {
                --i;
            } else {
                --j;
            }
            answer = Math.max(answer, j - i);
        }
        return answer;
    }

    private int deceitfulWar(double[] naomi, double[] ken) {
        int n = naomi.length;
        for (int k = n; k > 0; --k) {
            boolean ok = true;
            for (int i = 0; i < k; i++) {
                if (naomi[n - k + i] < ken[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return k;
            }
        }
        return 0;
    }
}

class InputReader {
    BufferedReader br;
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

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}

