
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
 
public class A {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		final int NUM_CASES = readInt();
		for(int casenum = 1; casenum <= NUM_CASES; casenum++)	{
			int n = readInt();
			int max = readInt();
			double[] total = new double[n];
			for(int i = 0; i < n; i++)
				total[i] = readDouble();
			double[] correctUpTo = new double[n+1];
			correctUpTo[0] = 1;
			for(int i = 1; i <= n; i++)
				correctUpTo[i] = correctUpTo[i-1] * total[i-1];
			double ret = (max+2);
			for(int i = n; i >= 0; i--)	{
				int numBackspace = (n-i);
				int numReturn = (max-i);
				int numForce = numBackspace + numReturn;
				double actual = 1+(correctUpTo[i] * (numForce) + (1-correctUpTo[i]) * (numForce + max + 1));
				ret = Math.min(ret, actual);
			}
			pw.print("Case #" + casenum + ": ");
			pw.println(ret);
		}
		pw.close();
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}
