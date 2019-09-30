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
		int X = ni();
		int K = ni();
		int[] r = new int[K+1];
		for(int i = 0;i < K;i++){
			r[i+1] = ni();
		}
		int[] infs = new int[K+1];
		int[] sups = new int[K+1];
		int[] bases = new int[K+1];
		infs[0] = 0;
		sups[0] = X;
		bases[0] = 0;
		
		for(int i = 1;i < K+1;i++){
			int t = r[i] - r[i-1];
			int dir = i&1; // 1:down, 0:up
			if(dir == 1){
				int nb = bases[i-1] - t;
				if(nb >= 0){
					infs[i] = infs[i-1];
					sups[i] = sups[i-1];
					bases[i] = nb;
				}else{
					infs[i] = infs[i-1] - nb;
					sups[i] = sups[i-1];
					if(infs[i] >= sups[i]){
						sups[i] = infs[i];
					}
					bases[i] = 0;
				}
			}else{
				int nb = bases[i-1] + t;
				if((long)nb + sups[i-1] - infs[i-1] <= X){
					infs[i] = infs[i-1];
					sups[i] = sups[i-1];
					bases[i] = nb;
				}else{
					infs[i] = infs[i-1];
					sups[i] = sups[i-1] - ((sups[i-1] - infs[i-1]+nb)-X);
					if(infs[i] >= sups[i]){
						sups[i] = infs[i];
					}
					bases[i] = X - (sups[i] - infs[i]);
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int Q = ni();Q > 0;Q--){
			int t = ni(), a = ni();
			int ind = Arrays.binarySearch(r, t);
			if(ind < 0)ind = -ind-2;
			int w = 0;
			if(a <= infs[ind]){
				w = bases[ind];
			}else if(a >= sups[ind]){
				w = bases[ind] + (sups[ind] - infs[ind]);
			}else{
				w = bases[ind] + (a - infs[ind]);
			}
			if((ind & 1) == 0){
				// down
				w -= t - r[ind];
				if(w < 0)w = 0;
			}else{
				w += t - r[ind];
				if(w > X)w = X;
			}
			sb.append(w).append("\n");
		}
		out.print(sb);
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