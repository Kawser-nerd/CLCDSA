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
		for(int Q = ni();Q > 0;Q--){
			int a = ni(), b = ni(), c = ni(), d = ni();
			int[] lrh = g(a, b);
			int L = lrh[0], R = lrh[1], H = lrh[2];
			int ra = a - H*L - R, rb = b - H*R - L;
			for(int i = c-1;i <= d-1;i++){
				if(i < (H+1)*L){
					if(i % (H+1) == H){
						out.print("B");
					}else{
						out.print("A");
					}
				}else if(i >= a+b - (H+1)*R){
					if((a+b-1-i) % (H+1) == H){
						out.print("A");
					}else{
						out.print("B");
					}
				}else if(i-(H+1)*L < ra){
					out.print("A");
				}else{
					out.print("B");
				}
			}
			out.println();
		}
	}
	
	static int[] g(int a, int b)
	{
		int h = (b+a)/(Math.min(a, b) + 1);
		int L = 0, R = 0;
		int ll = Math.min(a/h, b);
		if(0 < a-h*ll && a-h*ll <= h && b-ll <= h ||
			a-h*ll == 0 && b-ll <= h-1
			){
			L = ll;
			R = 0;
		}else{
			int low = 0, high = ll+1;
			while(high - low > 1){
				int mid = high+low>>1;
				int ra = a-mid*h, rb = b-mid;
				int rr = Math.min(rb/h, ra);
				ra -= rr; rb -= rr * h;
				if(ra >= h || ra <= h && rb <= h && 
						!(ra == h && rb == 0) &&
						!(ra == 0 && rb == h)){
					low = mid;
				}else{
					high = mid;
				}
			}
			if(low <= 0){
				L = 0;
				R = Math.min(b/h, a);
			}else{
				L = low;
				int ra = a-L*h, rb = b-L;
				R = Math.min(rb/h, ra);
			}
		}
		return new int[]{L, R, h};
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