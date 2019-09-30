import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {
	
	final String problem = "A";
//	final String filename = problem + "-sample";
//	final String filename= problem+"-small-attempt0";
//	final String filename= problem+"-small-attempt1";
	final String filename= problem+"-large";
	
	double best;
	
	final double eps = 1e-9;
	
	public void solve() throws Exception {
		int A = iread(), B = iread();
		double[] p = new double[A];
		for (int i=0; i<A; i++)
			p[i] = dread();
	
		best = 2 + B;
		double p1 = 0.0;
		for (int i=0; i<=A; i++) {
			double q = (A-i) + (B-i) + 1 + (1-Math.exp(p1)) * (B+1);
			best = Math.min(best, q);
			if (i<A) {
				if (p[i]<eps) 
					break;
				p1 += Math.log(p[i]);
			}
		}
	}
	
	public void solve_gcj() throws Exception
	{
		DecimalFormat df = new DecimalFormat("0.000000000");
		int tests = iread();
		for (int test=1; test<=tests; test++)
		{
			out.write("Case #"+test+": ");
			solve();
			out.write(df.format(best)+"\n");
		}
	}
	
	public void run() {
		try {
//			in = new BufferedReader(new InputStreamReader(System.in));
//			out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename+".in"));
			out = new BufferedWriter(new FileWriter(filename+".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}
	public static void main(String[] args) {
		try{
			Locale.setDefault(Locale.US);
		} catch (Exception e)
		{
			
		}
		new Thread(new Main()).start();
		//new Thread(null, new Main(), "1", 1<<25).start();
	}
}