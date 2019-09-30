import java.io.*;
import java.util.*;

public class triangle implements Runnable {
	private final String problemID = getClass().getName().toLowerCase() + "_small";
	private BufferedReader in;
	private PrintWriter out;
	
	private double det(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
		return a11 * (a22 * a33 - a32 * a23) - a12 * (a21 * a33 - a31 * a23) + a13 * (a21 * a32 - a31 * a22);
	}

	private void solveSingleTest(int testNumber) throws IOException {
		StringTokenizer st = new StringTokenizer(in.readLine());
		double x1 = Integer.parseInt(st.nextToken());
		double y1 = Integer.parseInt(st.nextToken());
		double x2 = Integer.parseInt(st.nextToken());
		double y2 = Integer.parseInt(st.nextToken());
		double x3 = Integer.parseInt(st.nextToken());
		double y3 = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(in.readLine());
		double xx1 = Integer.parseInt(st.nextToken());
		double yy1 = Integer.parseInt(st.nextToken());
		double xx2 = Integer.parseInt(st.nextToken());
		double yy2 = Integer.parseInt(st.nextToken());
		double xx3 = Integer.parseInt(st.nextToken());
		double yy3 = Integer.parseInt(st.nextToken());
		
		double a11 = x1 - xx1;
		double a12 = x2 - xx2;
		double a13 = x3 - xx3;
		double a21 = y1 - yy1;
		double a22 = y2 - yy2;
		double a23 = y3 - yy3;
		double a31 = 1.0;
		double a32 = 1.0;
		double a33 = 1.0;
		
		double d = det(a11, a12, a13, a21, a22, a23, a31, a32, a33);
		double d1 = a12 * a23 - a22 * a13;
		double d2 = -(a11 * a23 - a21 * a13);
		double d3 = (a11 * a22 - a12 * a21);
		double u = d1 / d;
		double v = d2 / d;
		double w = d3 / d;
		double x0 = u * x1 + v * x2 + w * x3; 
		double y0 = u * y1 + v * y2 + w * y3;
		
		if (Math.abs(a11 * u + a12 * v + a13 * w) > 1e-6) {
			System.out.println("Error");
		}
		if (Math.abs(a21 * u + a22 * v + a23 * w) > 1e-6) {
			System.out.println("Error");
		}
		if (Math.abs(u + v + w - 1.0) > 1e-6) {
			System.out.println("Error");
		}
		if (u < -1e-9 || v < -1e-9 || w < -1e-9) {
			out.println("Case #" + testNumber + ": No Solution");			
		} else {
			out.println("Case #" + testNumber + ": " + x0 + " " + y0);
		}
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + ".in")));
		out = new PrintWriter(new File(problemID + ".out"));
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 1; i <= n; i++) {
			solveSingleTest(i);
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) {
		new Thread(new triangle()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
