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
		int n = ni(), Q = ni();
		if(Q == 0){
			for(int i = 0;i < n;i++){
				out.println(1);
			}
			return;
		}
		long[] a = new long[Q];
		for(int i = 0;i < Q;i++){
			a[i] = nl();
		}
		int p = 0;
		for(int i = 0;i < Q;i++){
			while(p-1 >= 0 && a[p-1] >= a[i]){
				p--;
			}
			a[p++] = a[i];
		}
		a = Arrays.copyOf(a, p);
		long[] b = new long[p+1];
		b[0] = Math.min(n, a[0]);
		for(int i = 0;i < p;i++)b[i+1] = a[i];
		// 1211211211
		long[] imos = new long[n+1];
		long[] mul = new long[p+1];
		mul[p-1+1] = 1;
		for(int i = p-1;i >= 0;i--){
			long q = b[i+1];
			if(b[i+1] == b[i])continue;
			while(q >= b[0]){
				int ind = Arrays.binarySearch(b, 0, i+1, q);
				if(ind < 0){
					ind = -ind-2;
				}
				mul[ind] += q/b[ind]*mul[i+1];
				q %= b[ind];
			}
			imos[(int)q] -= mul[i+1];
			mul[i+1] = 0;
		}
		long z = imos[(int)b[0]];
		for(int i = (int)b[0]-1;i >= 1;i--){
			imos[i] = imos[i+1] - imos[i];
			z += imos[i];
		}
		long all = b[b.length-1];
		long plus = (all-z)/(b[0]);
		for(int i = (int)b[0];i >= 1;i--){
			imos[i] += plus;
		}
		for(int i = 1;i <= n;i++){
			out.println(imos[i]);
		}
	}
	
	public static void main(String[] args) throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(Math.abs(gen.nextLong() % 1000000000000000000L)+1 + "\n");
//		}
//		INPUT = sb.toString();

		
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