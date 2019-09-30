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
		int n = ni(), K = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++)a[i]--;
		int[] ia = new int[n];
		for(int i = 0;i < n;i++){
			ia[a[i]] = i;
		}
		
		int[] indeg = new int[n];
		int[] ft = new int[n+3];
		for(int i = 0;i < n;i++){
			indeg[ia[i]] = sumFenwick(ft, Math.min(n-1, ia[i]+K-1)) - sumFenwick(ft, ia[i]-K);
			addFenwick(ft, ia[i], 1);
		}
		
		StarrySkyTreePos sst = new StarrySkyTreePos(indeg);
		int[] ord = new int[n];
		for(int i = 0;i < n;i++){
			int argmin = sst.pos[1];
			ord[argmin] = i;
			sst.add(argmin, argmin + 1, 99999999);
			sst.add(Math.max(0, argmin-K+1), Math.min(argmin+K-1, n-1)+1, -1);
		}
		for(int i = 0;i < n;i++){
			out.println(ord[i] + 1);
		}
	}
	
	public static class StarrySkyTreePos {
		public int M, H, N;
		public int[] st;
		public int[] plus;
		public int[] pos;
		public int I = Integer.MAX_VALUE/4; // I+plus<int
		
		public StarrySkyTreePos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			plus = new int[H];
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 0;i--)propagate(i);
		}
		
		public StarrySkyTreePos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new int[H];
			Arrays.fill(st, H+N, M, I);
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[2*i] <= st[2*i+1]){
				st[i] = st[2*i] + plus[i];
				pos[i] = pos[2*i];
			}else{
				st[i] = st[2*i+1] + plus[i];
				pos[i] = pos[2*i+1];
			}
		}
		
		public void add(int l, int r, int v){ if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}
		
		private int min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				int ret = I;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret + plus[cur];
			}
		}
		
		public int[] minpos(int l, int r){ return l >= r ? null : minpos(l, r, 0, H, 1);}
		
		private int[] minpos(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return new int[]{st[cur], pos[cur]};
			}else{
				int mid = cl+cr>>>1;
				int[] L = null, R = null;
				if(cl < r && l < mid){
					L = minpos(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = minpos(l, r, mid, cr, 2*cur+1);
				}
				if(L == null && R == null)return null;
				if(R == null || L[0] <= R[0]){
					L[0] += plus[cur];
					return L;
				}else{
					R[0] += plus[cur];
					return R;
				}
			}
		}
		
		public int[] toArray() { return toArray(1, 0, H, new int[H]); }
		
		private int[] toArray(int cur, int l, int r, int[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
		}
	}

	
	
	
	public static int sumFenwick(int[] ft, int i) {
		int sum = 0;
		if(i < 0)return 0;
		for (i++; i > 0; i -= i & -i)
			sum += ft[i];
		return sum;
	}

	public static void addFenwick(int[] ft, int i, int v) {
		if (v == 0 || i < 0)
			return;
		int n = ft.length;
		for (i++; i < n; i += i & -i)
			ft[i] += v;
	}

	public static int findGFenwick(int[] ft, int v) {
		int i = 0;
		int n = ft.length;
		for (int b = Integer.highestOneBit(n); b != 0 && i < n; b >>= 1) {
			if (i + b < n) {
				int t = i + b;
				if (v >= ft[t]) {
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i + 1) : i - 1;
	}

	public static int valFenwick(int[] ft, int i) {
		return sumFenwick(ft, i) - sumFenwick(ft, i - 1);
	}

	public static int[] restoreFenwick(int[] ft) {
		int n = ft.length - 1;
		int[] ret = new int[n];
		for (int i = 0; i < n; i++)
			ret[i] = sumFenwick(ft, i);
		for (int i = n - 1; i >= 1; i--)
			ret[i] -= ret[i - 1];
		return ret;
	}

	public static int before(int[] ft, int x) {
		int u = sumFenwick(ft, x - 1);
		if (u == 0)
			return -1;
		return findGFenwick(ft, u - 1) + 1;
	}

	public static int after(int[] ft, int x) {
		int u = sumFenwick(ft, x);
		int f = findGFenwick(ft, u);
		if (f + 1 >= ft.length - 1)
			return -1;
		return f + 1;
	}

	public static int[] buildFenwick(int[] a) {
		int n = a.length;
		int[] ft = new int[n + 1];
		System.arraycopy(a, 0, ft, 1, n);
		for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
			for (int i = k; i <= n; i += k) {
				ft[i] += ft[i - h];
			}
		}
		return ft;
	}

	public static int[] buildFenwick(int n, int v) {
		int[] ft = new int[n + 1];
		Arrays.fill(ft, 1, n + 1, v);
		for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
			for (int i = k; i <= n; i += k) {
				ft[i] += ft[i - h];
			}
		}
		return ft;
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