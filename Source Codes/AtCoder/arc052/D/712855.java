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
		long K = nl();
		long m = nl();
		if(K == 1){
			out.println(m+1);
			return;
		}
		if(K >= 200000){
			int ct = 0;
			for(long i = 0;i <= m;i += K){
				for(long j = i;j <= i+91 && j <= m;j++){
					if(j == 0)continue;
					long dsum = 0;
					long num = j;
					while(num > 0){
						dsum += num%10;
						num/=10;
					}
					if(j % K == dsum % K){
						ct++;
					}
				}
			}
			out.println(ct);
		}else{
			char[] s = Long.toString(m).toCharArray();
			int ki = (int)K;
			long[] ps = new long[13];
			ps[0] = 1;
			for(int i = 0;i < 12;i++){
				ps[i+1] = ps[i] * 10 % K;
			}
			for(int i = 0;i <= 12;i++){
				ps[i]--;
				if(ps[i] < 0)ps[i] += K;
			}
			long[][] dp = new long[s.length+1][ki];
			long edge = 0;
			for(int i = 0;i < s.length;i++){
				for(int j = 0;j < ki;j++){
					for(int k = 0;k < 10;k++){
						int nj = (int)((j + ps[s.length-1-i] * k) % K);
						dp[i+1][nj] += dp[i][j];
					}
				}
				
				if(i == 0){
					for(int k = 1;k < s[i]-'0';k++){
						int nj = (int)(ps[s.length-1-i] * k % K);
						dp[i+1][nj]++;
					}
				}else{
					for(int k = 0;k < s[i]-'0';k++){
						int nj = (int)((edge + ps[s.length-1-i] * k) % K);
						dp[i+1][nj]++;
					}
					for(int k = 1;k <= 9;k++){
						int nj = (int)(ps[s.length-1-i] * k % K);
						dp[i+1][nj]++;
					}
				}
				edge = (edge + ps[s.length-1-i] * (s[i]-'0')) % K;
			}
			dp[s.length][(int)edge]++;
			out.println(dp[s.length][0]);
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