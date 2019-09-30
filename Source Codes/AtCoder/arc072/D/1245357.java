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
	
	public static String dtos(double x, int n) {
		StringBuilder sb = new StringBuilder();
		if(x < 0){
			sb.append('-');
			x = -x;
		}
		x += Math.pow(10, -n)/2;
//		if(x < 0){ x = 0; }
		sb.append((long)x);
		sb.append(".");
		x -= (long)x;
		for(int i = 0;i < n;i++){
			x *= 10;
			sb.append((int)x);
			x -= (int)x;
		}
		return sb.toString();
	}
	
	static void solve()
	{
		int n = ni(), L = ni();
		int[] ts = new int[n];
		int[] vs = new int[n];
		for(int i = 0;i < n;i++){
			ts[i] = ni();
			vs[i] = ni();
		}
		int tail = 0, head = 0;
		
		double[] qtv = new double[n];
		double[] qv = new double[n];
		
		double V = 0;
		double S = 0;
		for(int i = 0;i < n;i++){
			V += vs[i];
			S += (double)ts[i] * vs[i];
			while(V > L && tail < head){
				int ind = tail++;
				if(V - qv[ind] <= L){
					S -= qtv[ind] * (double)(V - L);
					qv[ind] = L - (V-qv[ind]);
					--tail;
					V = L;
				}else{
					V -= qv[ind];
					S -= (double)qtv[ind] * qv[ind];
				}
			}
			out.println(dtos(S/L, 10));
//			out.printf("%.14f\n", S/L);
			
			qtv[head] = ts[i];
			qv[head] = vs[i];
			head++;
			while(head - tail >= 2){
				int l1 = head-1, l2 = head-2;
				if(qtv[l2] < qtv[l1]){
					break;
				}else{
					qtv[l2] = (qtv[l1]*qv[l1]+qtv[l2]*qv[l2])/(qv[l1]+qv[l2]);
					qv[l2] += qv[l1];
					head--;
				}
			}
//			assert Math.abs(V-L) < 1e-9;
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