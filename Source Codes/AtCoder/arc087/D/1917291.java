import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i >= 1;i--){
			int cur = ord[i];
			des[par[cur]] += des[cur];
		}
		int[] gs = new int[2];
		int p = 0;
		outer:
		for(int i = 0;i < n;i++){
			for(int e : g[i]){
				if(par[i] == e)continue;
				if(des[e]*2 > n)continue outer;
			}
			if(i > 0)if((n-des[i])*2 > n)continue outer;
			gs[p++] = i;
		}
		int mod = 1000000007;
		if(p == 2){
			long ret = 1;
			for(int i = 1;i <= n/2;i++){
				ret = ret * i % mod;
			}
			out.println(ret*ret%mod);
		}else{
			int[] a = new int[n];
			int ap = 0;
			for(int e : g[gs[0]]){
				if(par[gs[0]] == e)continue;
				a[ap++] = des[e];
			}
			if(gs[0] > 0)a[ap++] = n - des[gs[0]];
			a = Arrays.copyOf(a, ap);
			out.println(dp(a, mod, n));
		}
	}
	
	static long dp(int[] a, int mod, int n)
	{
		// ???#invalid vetices??????????
		// (-1)^(invalid????)*(n-#invalid)! -- ???????:???DP?????????????
		// \prod_(each subtree)
		// C(subtree's size, #invalid vertices) invalid vertices???
		// C(subtree's size, #invalid vertices) invalid vertices???????
		// |#invalid vertices|! invalid vertices??????????
		
		// sum #invalid??????DP
		
		int ap = a.length;
		int[][] fif = enumFIF(6000, mod);
		long[] dp = new long[n+1];
		dp[0] = 1; // ?????
		for(int i = 0;i < ap;i++){
			long[] ndp = new long[n+1];
			for(int j = 0;j <= a[i];j++){ // num_invalid
				long comb = C(a[i], j, mod, fif);
				long mul = comb * comb % mod * fif[0][j] % mod;
				for(int k = 0;k+j <= n;k++){ // ???
					ndp[k+j] += dp[k] * mul;
					ndp[k+j] %= mod;
				}
			}
			dp = ndp;
		}
		
		long ret = 0;
		for(int i = 0, sg = 1;i <= n;i++, sg = mod - sg){
			ret += dp[i] * sg % mod * fif[0][n-i];
			ret %= mod;
		}
		
		return ret;
	}
	
	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n)
			return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}

	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
	}


	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}

	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}

	
	public static void main(String[] args) throws Exception
	{
//		int n = 5000, m = 70;
//		int[] a = new int[n/m];
//		Arrays.fill(a, m);
//		long S = System.currentTimeMillis();
//		dp(a, 1000000007, n);
//		long G = System.currentTimeMillis();
//		tr(G-S+"ms");

		
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	private static boolean eof()
	{
		if(lenbuf == -1)return true;
		int lptr = ptrbuf;
		while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
		
		try {
			is.mark(1000);
			while(true){
				int b = is.read();
				if(b == -1){
					is.reset();
					return true;
				}else if(!isSpaceChar(b)){
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
//	private static boolean isSpaceChar(int c) { return !(c >= 32 && c <= 126); }
	private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private static double nd() { return Double.parseDouble(ns()); }
	private static char nc() { return (char)skip(); }
	
	private static String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private static char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private static char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}