import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d:\n", casenum);
			final int NUM = readInt();
			int k = readInt();
			ArrayList<Long> valid = new ArrayList<Long>();
			for(int length = 2; length <= 4; length++) {
				long start = (1<<length)-1;
				while(start < (1L << NUM)) {
					if(start % 2 == 1 && Long.bitCount(start) == length) {
						valid.add(start);
					}
					start = nextNumber(start);
				}
			}
			Set<Long> set = new HashSet<Long>();
			for(long a: valid) {
				for(long b: valid) {
					long r = combine(a, b);
					if(r < (1L << NUM) && ((r & (1L << (NUM-1))) != 0 && Long.bitCount(a) * Long.bitCount(b) == Long.bitCount(r))) {
						if(!set.add(r)) continue;
						for(int i = NUM-1; i >= 0; i--) {
							if((r&(1L << i)) != 0) {
								pw.print(1);
							}
							else {
								pw.print(0);
							}
						}
						for(int x = 2; x <= 10; x++) {
							long now = 0;
							for(int i = NUM-1; i >= 0; i--) {
								now *= x;
								if((a&(1L << i)) != 0) {
									now++;
								}
							}
							pw.print(" ");
							pw.print(now);
						}
						pw.println();
						if(set.size() == k) break;
					}
				}
				if(set.size() == k) break;
			}
		}
		pw.close();
	}

	public static long nextNumber(long x)	{
		long u = x & (-x);
		long v = x + u;
		long y = v + (((v ^ x) / u) >> 2);
		return (long)y;
	}

	public static long combine(long a, long b) {
		long r = 0;
		for(int i = 0; i < 32; i++) {
			if((((b&(1L<<i)) != 0))) {
				r |= a << i;
			}
		}
		return r;
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
				st = new StringTokenizer(br.readLine());
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
