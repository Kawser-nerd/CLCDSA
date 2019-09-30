import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
//	static String INPUT = "31415926535897932384626433";
	
	// x=1.9
	// x^2=3.61
	// 
	
	static void solve()
	{
		BigInteger x = new BigInteger(ns());
		BigInteger y = x.add(BigInteger.ONE);
		BigInteger x2 = x.multiply(x);
		BigInteger y2 = y.multiply(y);
		String sx = x2.toString();
		String sy = y2.toString();
		for(int i = (sy.length()-1);i >= 1;i--){
			if(i >= sx.length())continue;
			String ssy = sy.substring(0, sy.length()-i);
			String ssx = sx.substring(0, sx.length()-i);
			BigInteger bssx = new BigInteger(ssx);
			BigInteger bssy = new BigInteger(ssy);
//			if(bssy.equals(bssx.add(BigInteger.ONE))){
//				out.println(bssy);
//				return;
//			}
//			tr(bssx, bssy);
			if(i % 2 == 0){
				boolean ok = false;
				for(int j = sx.length()-i;j < sx.length();j++){
					if(sx.charAt(j) != '0')ok = true;
				}
				if(!ok){
					out.println(bssx);
					return;
				}
			}
			
			if(bssy.compareTo(bssx) > 0 && i % 2 == 0){
				if(bssy.equals(bssx.add(BigInteger.ONE))){
					boolean ok = false;
					for(int j = sy.length()-i;j < sy.length();j++){
						if(sy.charAt(j) != '0')ok = true;
					}
					if(!ok)continue;
				}
				out.println(bssx.add(BigInteger.ONE));
				return;
			}
//			if(sy.charAt(i) == sx.charAt(i+sx.length()-sy.length())){
//				out.println(bssy);
//				return;
//			}
		}
		out.println(sx);
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