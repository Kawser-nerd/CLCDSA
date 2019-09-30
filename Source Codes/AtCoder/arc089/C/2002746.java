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
		// ax+by+c
		int A = ni(), B = ni();
		int[][] ds = new int[A][];
		for(int i = 0;i < A;i++){
			ds[i] = na(B);
		}
		
		int[][] es = new int[200000][];
		int p = 0;
		for(int c = 0;c <= 100;c++){
			for(int a = 0;a+c <= 100;a++){
				inner:
				for(int b = 0;a+b+c <= 100;b++){
					boolean hit = false;
					for(int i = 0;i < A;i++){
						for(int j = 0;j < B;j++){
							if(a*(i+1)+b*(j+1)+c < ds[i][j]){
								continue inner;
							}
							if(a*(i+1)+b*(j+1)+c == ds[i][j]){
								hit = true;
							}
						}
					}
					if(hit){
						es[p++] = new int[]{a, b, c};
					}
				}
			}
		}
		
		for(int i = 0;i < A;i++){
			for(int j = 0;j < B;j++){
				boolean hit = false;
				for(int k = 0;k < p;k++){
					if(es[k][0]*(i+1)+es[k][1]*(j+1)+es[k][2] == ds[i][j]){
						hit = true;
					}
				}
				if(!hit){
					out.println("Impossible");
					return;
				}
			}
		}
		out.println("Possible");
		
		out.println("300 " + (200+p));
		for(int i = 1;i <= 100;i++){
			out.println(i + " " + (i+1) + " X");
		}
		for(int i = 1;i <= 100;i++){
			out.println((i+110+1) + " " + (i+110) +  " Y");
		}
		for(int i = 0;i < p;i++){
			int[] e = es[i];
			out.println((1 + e[0]) + " " + (111 + e[1]) + " " + e[2]);
		}
		out.println(1 + " " + 111);
		
		tr(p);
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