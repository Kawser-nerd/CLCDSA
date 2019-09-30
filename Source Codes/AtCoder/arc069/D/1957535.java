import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(2);
		}
		int[][] xs = new int[2*n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			xs[p++] = new int[]{co[i][0], i};
			xs[p++] = new int[]{co[i][1], i+n};
		}
		Arrays.sort(xs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		int low = 0, high = 1000000007;
		while(high - low > 1){
			int h = high+low>>1;
			if(ok(h, xs)){
				low = h;
			}else{
				high = h;
			}
		}
		out.println(low);
	}
	
	static int flip(int x, int n)
	{
		return x < n ? x + n : x - n;
	}
	
	static long[] ft = new long[1300000];
	
	static boolean ok(int h, int[][] xs)
	{
		int p = 0;
		int n = xs.length;

		// (x1 and x2) or ... = false
		// (!x1 or !x2) and = true
		// x1 -> !x2, x2 -> !x1
		int q = 0;
		int H = 32768;
		// n=20000
		// 2^17+2n+4n*14?
		
		for(int i = 1;i < H;i++){
			ft[q++] = (long)i+n<<32|2*i+n;
			ft[q++] = (long)i+n<<32|2*i+1+n;
			ft[q++] = (long)2*i+n+2*H<<32|i+n+2*H;
			ft[q++] = (long)2*i+1+n+2*H<<32|i+n+2*H;
		}
		for(int i = 0;i < n;i++){
			ft[q++] = (long)H+i+n<<32|flip(xs[i][1], n/2);
			ft[q++] = (long)xs[i][1]<<32|H+i+n+2*H;
		}
		
		for(int i = 0;i < n;i++){
			while(p < i && xs[i][0] - xs[p][0] >= h){
				p++;
			}
			
			int l = p, r = i;
			if(l < r){
				while(l != 0){
					int f = l&-l;
					if(l+f > r)break;
					ft[q++] = (long)xs[i][1]<<32|(H+l)/f+n;
					ft[q++] = (long)(H+l)/f+n+2*H<<32|flip(xs[i][1], n/2);
					l += f;
				}
				
				while(l < r){
					int f = r&-r;
					ft[q++] = (long)xs[i][1]<<32|(H+r)/f-1+n;
					ft[q++] = (long)(H+r)/f-1+n+2*H<<32|flip(xs[i][1], n/2);
					r -= f;
				}
			}
		}
		int[][] g = packD(n+4*H, ft, q);
		int[] clus = decomposeToSCC(g);
		for(int i = 0;i < n/2;i++){
			if(clus[i] == clus[i+n/2])return false;
		}
		return true;
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

	
	public static int[][] packD(int n, long[] ft, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[(int)(ft[i]>>>32)]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[(int)(ft[i]>>>32)][--p[(int)(ft[i]>>>32)]] = (int)ft[i];
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