import java.util.*;
import java.io.*;
import java.math.*;

public class B
{
	public static void main(String[] argv) throws IOException
	{
		new B().run();
	}
	Scanner in;
	PrintWriter out;

	static final double EPS = 1e-8;

	boolean check(int d, double[] xs, double t){
		int n = xs.length;
		double px = xs[0] - t;
		for (int i = 1; i < n; i++){
			double nx = px + d;
			if (xs[i] < nx - t - EPS) return false;
			px = Math.max(xs[i] - t, nx);
		}
		return true;
	}

	double solve(int d, double[] xs){
		double l = 0, r = 1e14;
		for (int iter = 0; iter < 100; iter++){
			double q = (l + r) / 2.0;
			if (check(d, xs, q)) r = q;
			else l = q;
		}
		return (l + r) / 2.0;
	}

	public void run() throws IOException
	{
		boolean oj = System.getProperty("ONLINE_JUDGE") != null;
		in = oj ? new Scanner(System.in) : new Scanner(new File("input.txt"));
		out = oj ? new PrintWriter(System.out) : new PrintWriter(new File("output.txt"));

		int testNum = in.nextInt();
		for (int t = 0; t < testNum; t++){
			int c = in.nextInt();
			int d = in.nextInt();
			int n = 0;
			int[] ps = new int[c];
			int[] vs = new int[c];
			for (int i = 0; i < c; i++){
				ps[i] = in.nextInt();
				vs[i] = in.nextInt();
				n += vs[i];
			}
			double[] xs = new double[n];
			int pos = 0;
			for (int i = 0; i < c; i++){
				for (int j = 0; j < vs[i]; j++){
					xs[pos++] = ps[i];
				}
			}
			out.println("Case #" + (t+1) + ": " + solve(d, xs));
			out.flush();
		}
	}
}
