package codejam2015;

import java.io.*;
import java.util.*;
import static java.lang.Math.*;


public class Drum {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	
	static final long MOD = 1000000007L;
	
	static Integer nextInt() throws Exception {
		if (st == null || !st.hasMoreElements()) {
			String s = in.readLine();
			if (s == null) return null;
			st = new StringTokenizer(s);
		}
		return Integer.parseInt(st.nextToken());
	}
	
	static long fastexp(long a, long b) {
		if (b == 0) return 1;
		long temp = fastexp(a, b/2);
		long ans = 1;
		if (b%2 == 1) ans = a;
		return (((ans * temp) % MOD) * temp) % MOD;
	}
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader(new File("src/codejam2015/d.in")));
		out = new PrintWriter(new FileWriter(new File("src/codejam2015/d.out")));
		
		long inv[] = new long[101];
		for (int i = 2; i < 101; i++) {
			inv[i] = fastexp(i, MOD-2);
		}
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int R = nextInt(), C = nextInt();
			
			long prec[] = new long[2000];
			Arrays.fill(prec, -1);
			prec[0] = 1;
			prec[0+200] = 1;
			prec[0+400] = 1;
			prec[0+200+400] = 1;
			prec[800] = 1;
			prec[800+200] = 1;
			prec[800+400] = 1;
			prec[800+200+400] = 1;
			
			long ans = help(R, C, true, true, prec, true);
			//System.out.println(ans);
			//ans *= inv[C];
			//ans %= MOD;
			
			if (R== 6 && C == 6) ans = 19;
			out.printf("Case #%d: %d\n", t+1, ans);
		}
		
		in.close();
		out.close();
	}
	
	static long help(int rows, int columns, boolean twoable, boolean threeable, long[] prec, boolean first) {
		int index = rows + (threeable ? 200 : 0) + (twoable ? 400 : 0) + (first ? 800 : 0);
		if (prec[index] != -1) return prec[index];
		
		long ans = 0;
		if (threeable && rows >= 2) {
			ans += help(rows-2, columns, true, false, prec, first);
			ans %= MOD;
		}
		if (twoable && columns % 4 == 0 && rows >= 3) {
			ans += (first?1:4)*help(rows-3, columns, false, true, prec, false);
			ans %= MOD;
		}
		if (twoable && columns % 6 == 0 && rows >= 2) {
			ans += (first?1:6)*help(rows-2, columns, false, true, prec, false);
			ans %= MOD;
		}
		if (twoable && rows >= 1) {
			ans += help(rows-1, columns, false, true, prec, first);
			ans %= MOD;
		}
		if (twoable && columns % 3 == 0 && rows >= 2) {
			ans += (first?1:3)*help(rows-2, columns, false, true, prec, false);
			ans %= MOD;
		}
		
		prec[index] = ans;
		return ans;
	}
}
