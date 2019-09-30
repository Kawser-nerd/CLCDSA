import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		outer: for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			long x = readLong();
			long y = readLong();
			long g = gcd(x,y);
			x /= g;
			y /= g;
			long temp = y;
			while(temp%2==0) {
				temp /= 2;
			}
			if(temp != 1) {
				pw.println("impossible");
			}
			else {
				int ret = 0;
				while(x < y) {
					x *= 2;
					ret++;
				}
				pw.println(ret);
			}
		}
		pw.close();
	}

	public static long gcd(long a, long b) {
		if(a==0) return b;
		if(b==0) return a;
		return gcd(b,a%b);
	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine(), "/");
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
