import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		long[] F = new long[88];
		F[0] = F[1] = 1;
		for(int i = 2;i < 88;i++){
			F[i] = F[i-1] + F[i-2];
		}
		
		List<List<long[]>> sp = new ArrayList<>();
		for(int i = 0;i < 87;i++){
			sp.add(new ArrayList<>());
		}
		
		for(int j = -1;j < 87;j++){
			long a = 1, b = 1;
			for(int k = 0;k < 87;k++){
				if(j < k-1){
					sp.get(k).add(new long[]{a, b});
					if(a != b){
						sp.get(k).add(new long[]{b, a});
					}
				}
				long c = a + b;
				if(k == j)c += b;
				a = b; b = c;
			}
		}
		sp.get(1).clear();
		sp.get(1).add(new long[]{1L, 1L});
		sp.get(1).add(new long[]{2L, 2L});
		
//		int v = 0;
//		for(List<long[]> u : sp){
//			tr(v, F[v]);
//			for(long[] o : u){
//				tr(o);
//			}
//			v++;
//		}
		
		int mod = 1000000007;
		for(int Q = ni();Q > 0;Q--){
			long X = nl(), Y = nl();
			int hit = 1;
			for(int i = 86;i >= 2;i--){
				if(F[i] <= X && F[i+1] <= Y || F[i+1] <= X && F[i] <= Y){
					hit = i;
					break;
				}
			}
			long ans = 0;
			for(long[] t : sp.get(hit)){
				if(t[0] <= X && t[1] <= Y){
					if(t[0] <= t[1]){
						ans += (Y-t[1])/t[0]+1;
					}
					if(t[0] >= t[1]){
						ans += (X-t[0])/t[1]+1;
					}
					if(t[0] == t[1]){
						ans += mod-1;
					}
					ans %= mod;
				}
			}
			out.println(hit + " " + ans);
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