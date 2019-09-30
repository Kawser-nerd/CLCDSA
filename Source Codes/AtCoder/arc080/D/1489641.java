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
		int[] a = na(n);
		int[] b = new int[2*n];
		int p = 0;
		for(int i = 0;i < n;i++){
			b[p++] = a[i];
			b[p++] = a[i]+1;
		}
		int q = 0;
		for(int i = 0;i < 2*n;i++){
			if(i+1 < 2*n && b[i] == b[i+1]){
				i++;
				continue;
			}
			b[q++] = b[i];
		}
		b = Arrays.copyOf(b, q);
		
		int pe = 0, po = 0;
		int[] be = new int[q];
		int[] bo = new int[q];
		for(int v : b){
			if(v % 2 == 0){
				be[pe++] = v;
			}else{
				bo[po++] = v;
			}
		}
		be = Arrays.copyOf(be, pe);
		bo = Arrays.copyOf(bo, po);
		
		long[] isp = isp(11000000);
		boolean[][] g = new boolean[pe][po];
		for(int i = 0;i < pe;i++){
			for(int j = 0;j < po;j++){
				int s = Math.abs(be[i] - bo[j]);
				if(isp[s>>>6]<<~s<0){
					g[i][j] = true;
				}
			}
		}
		int F = doBipartiteMatchingHK(g);
		out.println(F + (pe-F)/2*2 + (po-F)/2*2 + ((pe-F)%2 == 1 ? 3 : 0));
	}
	
	public static int doBipartiteMatchingHK(boolean[][] g)
	{
		int n = g.length;
		if(n == 0)return 0;
		int m = g[0].length;
		int[] from = new int[m];
		int[] to = new int[n];
		Arrays.fill(to, -1);
		Arrays.fill(from, n);
		
		int[] d = new int[n+1];
		int mat = 0;
		while(true){
			Arrays.fill(d, -1);
			int[] q = new int[n];
			int r = 0;
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					d[i] = 0;
					q[r++] = i;
				}
			}
			
			for(int p = 0;p < r;p++) {
				int cur = q[p];
				for(int adj = 0;adj < m;adj++){
					if(g[cur][adj]){
						int nex = from[adj];
						if(d[nex] == -1) {
							if(nex != n)q[r++] = nex;
							d[nex] = d[cur] + 1;
						}
					}
				}
			}
			if(d[n] == -1)break;
			
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					if(dfsHK(d, g, n, m, to, from, i))mat++;
				}
			}
		}
		
		return mat;
	}
	
	static boolean dfsHK(int[] d, boolean[][] g, int n, int m, int[] to, int[] from, int cur)
	{
		if(cur == n)return true;
		for(int adj = 0;adj < m;adj++){
			if(g[cur][adj]){
				int nex = from[adj];
				if(d[nex] == d[cur] + 1 && dfsHK(d, g, n, m, to, from, nex)){
					to[cur] = adj;
					from[adj] = cur;
					return true;
				}
			}
		}
		d[cur] = -1;
		return false;
	}

	
	
	
	
	public static long[] isp(int n)
	{
		int[] tprimes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
		if(n <= 64){
			long ptn = 0;
			for(int p : tprimes)if(p <= n)ptn |= 1L<<p;
			return new long[]{ptn};
		}
		
		long[] isnp = new long[(n+1)/64+1];
		int sup = (n+1)/64+1;
		
		isnp[0] |= 1<<1;
		for(int tp : tprimes){
			long[] ptn = new long[tp];
			for(int i = 0;i < tp<<6;i+=tp)ptn[i>>>6] |= 1L<<i;
			for(int j = 0;j < sup;j += tp){
				for(int i = 0;i < tp && i+j < sup;i++){
					isnp[j+i] |= ptn[i];
				}
			}
		}
		
		final int[] magic = {0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28, 62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11, 63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10, 51, 25, 36, 32,
	              60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12};
		out:
		for(int i = 0;i < sup;i++){
			for(long j = ~isnp[i];j != 0;j &= j-1){
				int p = i<<6|magic[(int)((j&-j)*0x022fdd63cc95386dL>>>58)];
				if((long)p*p > n)break out;
				for(int q = p*p;q <= n;q += p)isnp[q>>6] |= 1L<<q;
			}
		}
		
		for(int i = 0;i < isnp.length;i++)isnp[i] = ~isnp[i];
		for(int tp : tprimes)isnp[0] |= 1L<<tp;
		isnp[isnp.length-1] &= (1L<<n+1)-1;
		
		return isnp;
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