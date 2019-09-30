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
		int n = ni(), V = ni();
		int[] x = na(n);
		String IMP = "Impossible";
		String P = "Possible";
		int[] ws = new int[20];
		int p = 0;
		for(int w = V;w >= 0;w/=2){
			ws[p++] = w;
			if(w == 0)break;
		}
		
		DJSet ds = new DJSet(n);
		int[][] tos = new int[20][];
		for(int i = p-1;i >= 0;i--){
			tos[i] = new int[n];
			for(int j = 0;j < n-1;j++){
				if(x[j+1] - x[j] <= ws[i]){
					ds.union(j, j+1);
				}
			}
			for(int j = 0;j < n;j++){
				tos[i][j] = ds.max[ds.root(j)];
			}
		}
		if(ds.count() > p){
			for(int i = 0;i < n;i++){
				out.println(IMP);
			}
			return;
		}
		
		for(int i = 0;i < n;){
			int right = ds.max[ds.root(i)];
			// [i,right]
			int[] reach = new int[1<<p-1];
			Arrays.fill(reach, -1);
			reach[0] = i == 0 ? right : -1;
			for(int j = 0;j < 1<<p-1;j++){
				for(int k = 0;k < p-1;k++){
					if(j<<~k>=0){
						int ne = reach[j] + 1;
						if(ne == n){
							reach[j|1<<k] = n-1;
							continue;
						}
						int nval = tos[k+1][ne];
						if(i-1 <= nval && nval <= right){
							nval = right;
						}
						reach[j|1<<k] = Math.max(reach[j|1<<k], nval);
					}
				}
			}
			if(reach[(1<<p-1)-1] == n-1){
				for(int k = i;k <= right;k++){
					out.println(P);
				}
			}else{
				for(int k = i;k <= right;k++){
					out.println(IMP);
				}
			}
			i = ds.max[ds.root(i)]+1;
		}
	}
	
	public static class DJSet {
		public int[] upper;
		public int[] min;
		public int[] max;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			min = new int[n];
			for(int i = 0;i < n;i++)min[i] = i;
			max = Arrays.copyOf(min, n);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				min[x] = Math.min(min[x], min[y]);
				max[x] = Math.max(max[x], max[y]);
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
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