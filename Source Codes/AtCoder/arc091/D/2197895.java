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
		int n = ni();
		int nim = 0;
		for(int i = 0;i < n;i++){
			int a = ni(), K = ni();
			nim ^= nim(a, K);
		}
		if(nim == 0){
			out.println("Aoki");
		}else{
			out.println("Takahashi");
		}
	}
	
	static int[] starts = new int[100000];
	static int[] lens = new int[100000];
	static int[] reps = new int[100000];
	
	static int nim(int n, int K)
	{
		if(K == 1)return n;
		int start = K-1;
		int len = 1;
		if(n < K)return 0;
		
		int p = 0;
		starts[p] = start;
		lens[p] = len;
		p++;
		
		for(int rep = 0;start <= n;rep++){
			// plus = (start + nlen) / K - start / K
			// nlen = len + plus
			
			// start%K + len*x < K
			// x < (K-start%K)/len
			int skip = (K-1-start%K)/len;
			start += len*skip;
			reps[p-1] = skip;
			
			int low = len-1, high = 2*len+1;
			while(high - low > 1){
				int h = high+low>>>1;
				int plus = (start + h) / K - start / K;
				if(h >= len + plus){
					high = h;
				}else{
					low = h;
				}
			}
			len = high;
			start += len;
			starts[p] = start;
			lens[p] = len;
			p++;
		}
		for(int i = 0;i < p;i++){
			starts[i] -= lens[i];
		}
//		tr(starts);
//		tr(reps);
//		tr(lens);
		int cur = p-1;
		int ind = (n - starts[cur]);
		if(ind < 0){
			cur--;
			ind = (n - starts[cur]);
		}
//		tr(n, cur, ind);
		
		while(cur > 0){
			int pos = starts[cur] + ind;
			if(pos % K == 0){
				return pos / K;
			}
			ind %= lens[cur];
			pos = starts[cur] + ind;
			ind -= pos/K - starts[cur]/K;
			cur--;
			if(pos % K == 0){
				return pos / K;
			}
		}
		
		return 0;
	}
	// 0,1,2,4,7,11,17,26,40
	// 3,5,8,13,20,31,47,71
	
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