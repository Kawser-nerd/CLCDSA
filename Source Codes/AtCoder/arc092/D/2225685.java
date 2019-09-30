import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packD(n, from, to);
		int[] clus = decomposeToSCC(g);
		int[][][] cg = condense(g, clus);
		
		int u = cg.length;
		int[][] dp = new int[u][u];
		for(int i = 0;i < u;i++){
			dp[i][i] = 1;
			for(int j = i;j >= 0;j--){
				for(int[] e : cg[j]){
					dp[i][e[0]] = Math.min(2, dp[i][e[0]] + dp[i][j] * e[1]);
				}
			}
		}
		
		int[] ep = new int[n];
		Set<Long> chas = new HashSet<>();
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int e : g[i]){
				if(clus[i] == clus[e]){
					ep[p++] = e;
				}
			}
			long[][] done = new long[p+1][(n>>>6)+1];
			done[0][i>>>6] |= 1L<<i;
			for(int j = 0;j < p;j++){
				for(int k = 0;k < done[j].length;k++){
					done[j+1][k] = done[j][k];
				}
				dfs(done[j+1], ep[j], g, clus);
			}
			
			long[][] doneb = new long[p+1][(n>>>6)+1];
			doneb[p][i>>>6] |= 1L<<i;
			for(int j = p-1;j >= 0;j--){
				for(int k = 0;k < doneb[j].length;k++){
					doneb[j][k] = doneb[j+1][k];
				}
				dfs(doneb[j], ep[j], g, clus);
			}
			for(int j = 0;j < p;j++){
				if((done[j][ep[j]>>>6]|doneb[j+1][ep[j]>>>6])<<~ep[j]>=0){
					chas.add((long)i<<32|ep[j]);
				}
			}
		}
		
		for(int i = 0;i < m;i++){
			if(clus[from[i]] != clus[to[i]]){
				if(dp[clus[from[i]]][clus[to[i]]] == 2){
					out.println("diff");
				}else{
					out.println("same");
				}
			}else{
				if(chas.contains((long)from[i]<<32|to[i])){
					out.println("diff");
				}else{
					out.println("same");
				}
			}
		}
	}
	
	static void dfs(long[] done, int cur, int[][] g, int[] clus)
	{
		for(int e : g[cur]){
			if(clus[e] == clus[cur] && done[e>>>6]<<~e>=0){
				done[e>>>6] |= 1L<<e;
				dfs(done, e, g, clus);
			}
		}
	}
	
	public static int[][][] condense(int[][] g, int[] clus)
	{
		int n = g.length;
		int m = 0;
		for(int i = 0;i < n;i++)m = Math.max(m, clus[i]);
		m++;
		
		int[] cp = new int[m];
		for(int i = 0;i < n;i++){
			cp[clus[i]] += g[i].length;
		}
		int[][] c = new int[m][];
		int[][][] cg = new int[m][][];
		for(int i = 0;i < m;i++){
			c[i] = new int[cp[i]];
			cg[i] = new int[cp[i]][];
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				c[clus[i]][--cp[clus[i]]] = clus[g[i][j]];
			}
		}
		
		for(int i = 0;i < m;i++){
			Arrays.sort(c[i]);
			int jp = 0;
			for(int j = 0;j < c[i].length;){
				int k = j;
				while(k < c[i].length && c[i][j] == c[i][k])k++;
				if(c[i][j] != i){
					cg[i][jp++] = new int[]{c[i][j], k-j};
				}
				j = k;
			}
			cg[i] = Arrays.copyOf(cg[i], jp);
		}
		return cg;
	}

	
	public static int[] decomposeToSCC(int[][] g)
	{
		int n = g.length;
		int[] stack = new int[n+1];
		int[] ind = new int[n+1];
		int[] ord = new int[n];
		Arrays.fill(ord, -1);
		int[] low = new int[n];
		Arrays.fill(low, -1);
		int sp = 0;
		int id = 0; // preorder
		int[] clus = new int[n];
		int cid = 0;
		int[] cstack = new int[n+1];
		int csp = 0;
		boolean[] incstack = new boolean[n];
		for(int i = 0;i < n;i++){
			if(ord[i] == -1){
				ind[sp] = 0;
				cstack[csp++] = i;
				stack[sp++] = i;
				incstack[i] = true;
				while(sp > 0){
					int cur = stack[sp-1];
					if(ind[sp-1] == 0){
						ord[cur] = low[cur] = id++;
					}
					if(ind[sp-1] < g[cur].length){
						int nex = g[cur][ind[sp-1]];
						if(ord[nex] == -1){
							ind[sp-1]++;
							ind[sp] = 0;
							incstack[nex] = true;
							cstack[csp++] = nex;
							stack[sp++] = nex;
						}else{
							// shortcut
//							U.tr(cur, nex, incstack[nex], low[nex], stack);
							if(incstack[nex])low[cur] = Math.min(low[cur], low[nex]);
							ind[sp-1]++;
						}
					}else{
						if(ord[cur] == low[cur]){
							while(csp > 0){
								incstack[cstack[csp-1]] = false;
								clus[cstack[--csp]] = cid;
								if(cstack[csp] == cur)break;
							}
							cid++;
						}
						if(--sp >= 1)low[stack[sp-1]] = Math.min(low[stack[sp-1]], low[stack[sp]]);
					}
				}
			}
		}
		return clus;
	}

	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}

	
	public static void main(String[] args) throws Exception
	{
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