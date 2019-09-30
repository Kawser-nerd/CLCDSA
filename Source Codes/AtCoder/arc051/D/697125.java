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
		int w = ni(), h = ni();
		int[] a = na(w);
		int[] b = na(h);
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni()-1, i};
		}
		long[][] ta = go(a, qs, 0);
		long[][] tb = go(b, qs, 1);
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		// W*h[j]+j*M
		// W*(h[j]-h[i])+(j-i)*M
		// W*max+h*M
		// 1*max+h*10
		// 2*max+h*10
		for(int i = 0;i < Q;i++){
			EnvelopeLinear el = new EnvelopeLinear(qs[i][0]+1);
			for(int j = 1;j <= qs[i][0]+1;j++){
				el.add(-j, -ta[i][j]);
			}
//			tr(el.slopes);
//			tr(el.intercepts);
//			tr(el.xs);
			long max = Long.MIN_VALUE;
			for(int j = 1;j <= qs[i][1]+1;j++){
				int which = el.argmin((double)tb[i][j]/j);
				max = Math.max(max, -el.slopes[which]*tb[i][j] - j*el.intercepts[which]);
			}
			out.println(max);
		}
	}
	
	public static class EnvelopeLinear {
		public static final long INF = Integer.MIN_VALUE;
		
		public double[] xs;
		public long[] intercepts, slopes;
		public int p;
		
		public EnvelopeLinear(int n)
		{
			xs = new double[n];
			intercepts = new long[n];
			slopes = new long[n];
			p = 0;
		}
		
		public void add(long slope, long intercept)
		{
			for(int i = p-1;i >= 0;i--){
				if(intercept+xs[i]*slope <= intercepts[i]+xs[i]*slopes[i]){ // x=xs[i]
					p--;
					continue;
				}
				if(slope == slopes[i]){
					if(intercept >= intercepts[i]){
						return;
					}else{
						continue;
					}
				}
				// y=sx+i vs y=Sx+I
				// sx+i=Sx+I
				// x=(i-I)/(S-s)
				long num = intercept-intercepts[i];
				long den = slopes[i]-slope;
				double nx = (double)num/den;
				xs[p] = nx;
				intercepts[p] = intercept;
				slopes[p] = slope;
				p++;
				return;
			}
			
			xs[p] = INF;
			intercepts[p] = intercept;
			slopes[p] = slope;
			p++;
		}
		
		public int argmin(double x)
		{
			if(p <= 0)throw new RuntimeException();
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return ind;
		}
//		public long min(double x)
//		{
//			if(p <= 0)return Long.MIN_VALUE / 5;
//			int ind = Arrays.binarySearch(xs, 0, p, x);
//			if(ind < 0)ind = -ind-2;
//			return slopes[ind]*x + intercepts[ind];
//		}
	}
	
	static long[][] go(int[] a, int[][] qs, int ind)
	{
		int Q = qs.length;
		int w = a.length;
		long[] cum = new long[w+1];
		for(int i = 0;i < w;i++){
			cum[i+1] = cum[i] + a[i];
		}
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[ind] - b[ind];
			}
		});
		
		long[] maxs = new long[w+1];
		Arrays.fill(maxs, -500000000);
		maxs[0] = 0;
		long[][] tw = new long[Q][];
		int x = 0;
		for(int i = 0;i < Q;i++){
			while(x <= qs[i][ind]){
				for(int j = 1;j <= x+1;j++){
					maxs[j] = Math.max(maxs[j], cum[x+1]-cum[x+1-j]);
				}
				x++;
			}
			tw[qs[i][2]] = Arrays.copyOf(maxs, w+1);
		}
		return tw;
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