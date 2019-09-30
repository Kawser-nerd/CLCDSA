import java.lang.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br;
	public static PrintWriter out;
	public static StringTokenizer stk;

	// ///////////////// TO CHANGE ///////////////////////////
	public static boolean isServer = false;

	// ///////////////// TO CHANGE ///////////////////////////

	public static void main(String[] args) throws IOException {
		if (isServer) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter(new File("out.txt"));
		}

		(new Solution()).run();
	}

	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
	}

	public String nextWord() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return stk.nextToken();
	}

	public Integer nextInt() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Integer.valueOf(stk.nextToken());
	}

	public Long nextLong() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Long.valueOf(stk.nextToken());
	}

	public Double nextDouble() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Double.valueOf(stk.nextToken());
	}

	public Float nextFloat() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Float.valueOf(stk.nextToken());
	}
	
	long gcd(long a, long b) {
		if (b==0) return a;
		else return gcd(b, a%b);
	}
	
	public void run() {
		int tt = nextInt();
		for (int t = 0; t < tt; t++) {
			out.printf("Case #%d: ", t+1);
			long n = nextLong();
			long pd = nextLong();
			long pg = nextLong();
			long D = 100 / gcd(100, pd);
			long x = D * pd / 100;
			System.out.printf("%d %d\n", D, x);
			if (D <= n) {
				/*
				long G = 100 / gcd(100, pg);
				long y = G * pg / 100;
				if (G < D) {
					long mul = G/D;
					if (G * mul < D) {
						mul++;
					}
					G *= mul;
					y *= mul;
				}
				System.out.printf("%d %d\n", G, y);
				*/
				if (pd < 100 && pg == 100) out.println("Broken");
				else if (pd > 0 && pg == 0) out.println("Broken");
				else out.println("Possible");
			} else {
				out.println("Broken");
			}
		}
		out.flush();
	}
}
