import java.util.*;
import java.io.*;

public class Triangles implements Runnable {
	private final String problemID = getClass().getName();
	private final String problemType = "small";
	private BufferedReader in;
	private PrintWriter out;
	
	private int lastX, lastY;
	private boolean isGood(int a, int n, int m) {
		for (int i = 1; i <= n; i++) {
			int num = a / i;
			if (num > m) {
				continue;
			}
			if (a - num * i != 0) {
				continue;
			}
			lastX = i;
			lastY = num;
			return true;
		}
		return false;
	}
	
	private void smallCaseSolver(int testNumber, int n, int m, int a) {
		for (int x = 0; x <= n; x++) {
			for (int y = 0; y <= m; y++) {
				int num = a + x * y;
				if (isGood(num, n, m)) {
					out.println("Case #" + testNumber + ": 0 0 " + lastX + " " + y + " " + x + " " + lastY);
					return;
				}
			}
		}
		out.println("Case #" + testNumber + ": IMPOSSIBLE");
	}

	private void solveSingleTest(int testNumber) throws IOException {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());
		
		if (n <= 100 && m <= 100) {
			smallCaseSolver(testNumber, n, m, a);
			return;
		}
	}
	
	public static void main(String[] args) {
		new Thread(new Triangles()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + "_" + problemType + ".in")));
		out = new PrintWriter(new File(problemID + "_" + problemType + ".out"));
		
		int testsNumber = Integer.parseInt(in.readLine());
		for (int i = 0; i < testsNumber; i++) {
			solveSingleTest(i + 1);
		}
		
		in.close();
		out.close();
	}
}
