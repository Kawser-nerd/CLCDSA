import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintStream;
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
			inputStream = new FileInputStream("b.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        double farmCosts = in.nextDouble();
        double farmGives = in.nextDouble();
        double wantCookies = in.nextDouble();
        double answer = solve(farmCosts, farmGives, wantCookies);
        out.println("Case #" + testNumber + ": " + answer);
    }

    private double solve(double farmCosts, double farmGives, double wantCookies) {
        double timeToMakeFarms = 0;
        double lastTime = Double.POSITIVE_INFINITY;
        for (int farms = 0; ; farms++) {
            double curTime = timeToMakeFarms + wantCookies / (2 + farmGives * farms);
            if (curTime > lastTime) {
                System.err.println("farms: " + farms);
                return lastTime;
            }
            lastTime = curTime;
            timeToMakeFarms += farmCosts / (2 + farmGives * farms);
        }
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

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}

