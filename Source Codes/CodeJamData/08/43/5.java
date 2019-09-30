import java.util.*;
import java.io.*;

public class Star implements Runnable {
	private static final double eps = 1e-9;
	private final String problemID = getClass().getName();
	private final String problemType = "big";
	private BufferedReader in;
	private PrintWriter out;
	
	private void solveSingleTest(int testNumber) throws IOException {
		int n = Integer.parseInt(in.readLine());
		int[] x = new int[n];
		int[] y = new int[n];
		int[] z = new int[n];
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			y[i] = Integer.parseInt(st.nextToken());
			z[i] = Integer.parseInt(st.nextToken());
			p[i] = Integer.parseInt(st.nextToken());
		}
		double[] d = new double[n];
		double low = 0.0;
		double hi = 1e8;
		while (low + eps < hi) {
			double middle = (low + hi) / 2;
			for (int i = 0; i < n; i++) {
				d[i] = middle * p[i];
			}
			boolean bad = false;
			for (int mask = 0; mask < 4; mask++) {
				double min = calcCoef(mask, 0, x, y, z) - d[0];
				double max = calcCoef(mask, 0, x, y, z) + d[0];
				for (int i = 0; i < n; i++) {
					double cur = calcCoef(mask, i, x, y, z);
					min = Math.max(min, cur - d[i]);
					max = Math.min(max, cur + d[i]);
				}
				if (min > max) {
					bad = true;
				}
			}
			if (bad) {
				low = middle;
			} else {
				hi = middle;
			}
		}
		out.println("Case #" + testNumber + ": " + low);
	}
	
	private double calcCoef(int mask, int i, int[] x, int[] y, int[] z) {
		double answer = 0;
		if ((mask & 1) != 0) {
			answer += x[i];
		} else {
			answer -= x[i];
		}
		if ((mask & 2) != 0) {
			answer += y[i];
		} else {
			answer -= y[i];
		}
		if ((mask & 4) != 0) {
			answer += z[i];
		} else {
			answer -= z[i];
		}
		return answer;
	}

	public static void main(String[] args) {
		new Thread(new Star()).start();
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
