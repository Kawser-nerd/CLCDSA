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
	static final String FI = "First";
	static final String SE = "Second";
	
	static void solve()
	{
		int n = ni();
		int[] a = na(n);
		boolean win = go(a);
		if(win){
			out.println(FI);
		}else{
			out.println(SE);
		}
	}
	
	static boolean go(int[] a)
	{
		int n = a.length;
		if(n == 1){
			return a[0] >= 2;
		}else if(n == 2){
			if(Arrays.stream(a).anyMatch(x -> x == 1)){
				int h = 0;
				for(int v : a){
					h ^= v-1;
				}
				h &= 1;
				return h == 1;
			}
			int h = 0;
			int o = 0;
			for(int v : a){
				h ^= v-1;
				o += v&1;
			}
			h &= 1;
			assert o >= 1;
			if(o == 2){
				if(h == 1){
					for(int i = 0;i < n;i++){
						a[i] = a[i]/2*2;
					}
					return go(fall(a));
				}else{
					return false;
				}
			}else{
				if(h == 0){
					for(int i = 0;i < n;i++){
						a[i] = a[i]/2*2;
					}
					return !go(fall(a));
				}else{
					return true;
				}
			}
		}else{
			if(Arrays.stream(a).anyMatch(x -> x == 1)){
				int h = 0;
				for(int v : a){
					h ^= v-1;
				}
				h &= 1;
				return h == 1;
			}
			int h = 0;
			int o = 0;
			for(int v : a){
				h ^= v-1;
				o += v&1;
			}
			h &= 1;
			assert o >= 1;
			if(o >= 2){
				return h == 1;
			}else{
				if(h == 0){
					for(int i = 0;i < n;i++){
						a[i] = a[i]/2*2;
					}
					return !go(fall(a));
				}else{
					return true;
				}
			}
		}
	}
	
	static int[] fall(int[] a)
	{
		int g = 0;
		for(int i = 0;i < a.length;i++){
			g = gcd(a[i], g);
		}
		for(int i = 0;i < a.length;i++){
			a[i] /= g;
		}
		return a;
	}
	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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