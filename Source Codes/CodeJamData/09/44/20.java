import java.awt.geom.Point2D;
import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

public class Program implements Runnable{
	private static BufferedReader br;
	private static PrintWriter out;
	private static StringTokenizer stk;
	
	public static void main(String[] args) throws FileNotFoundException {
		br = new BufferedReader(new FileReader("D:\\D-small-attempt3.in"));
		out = new PrintWriter(new File("D:\\D-out.txt"));
		(new Thread(new Program())).start();
	}
	
	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private String nextLine() {
		try {
			return br.readLine();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	private Integer nextInt() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	private Long nextLong() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	private Double nextDouble() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	private String nextWord() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return stk.nextToken();
	}
	
	public void run() {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			int n = nextInt();
			double[] x = new double[n];
			double[] y = new double[n];
			double[] r = new double[n];
			
			for (int i = 0; i < n; ++i) {
				x[i] = nextDouble();
				y[i] = nextDouble();
				r[i] = nextDouble();
			}
			double res = 0;
			if (n == 1) {
				res = r[0];
			}
			else if (n==2) {
				res = Math.max(r[0], r[1]);
			}
			else if (n==3) {
			res = Double.MAX_VALUE;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i != j) {
						double max = 0;
						for (int k = 0; k < n; ++k) {
							if (i!=k && j!=k) {
								max = Math.max(max, r[k]);
							}
						}
						res = Math.min(res, Math.max(max, r[i] + r[j] + Point2D.distance(x[i], y[i], x[j], y[j])));
					}
				}
			}
			res /= 2.0;
			}
			out.printf(Locale.ENGLISH, "Case #%d: %.8f", tt+1, res);
			out.println();
		}
		out.flush();
	}
	
}
