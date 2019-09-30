import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Set;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int mod = 1000000007;
		int n = ni();
		int[] a = na(n-1);
		int[][] ps = enumPartitions(n)[n];
		int m = ps.length;
		Map<Long, Integer> map = new HashMap<>();
		for(int i = 0;i < m;i++){
			map.put(h(ps[i]), i);
		}
		
		long[] dp = new long[m];
		dp[0] = 1;
		int w = 1;
		for(int i = 0;i < n-1;i++){
			while(w < a[i]){
				for(int j = 0;j < m;j++){
					int rem = 0;
					for(int k = 1;k <= n;k++){
						rem += (k*(k-1)/2-(k-1))*ps[j][k];
					}
					rem -= w-1-i;
					if(rem > 0){
						dp[j] = dp[j] * rem % mod;
					}else{
						dp[j] = 0;
					}
				}
				w++;
			}
			
			long[] ndp = new long[m];
			for(int j = 0;j < m;j++){
				if(dp[j] == 0)continue;
				for(int k = 1;k <= n;k++){
					if(ps[j][k] >= 1){
						ps[j][k]--;
						for(int l = k;l <= n;l++){
							if(ps[j][l] >= 1){
								ps[j][l]--;
								ps[j][k+l]++;
								int to = map.get(h(ps[j]));
								ps[j][k+l]--;
								ndp[to] += dp[j] * (k == l ? ((ps[j][k]+2)*k)*(((ps[j][k]+2)*k)-1)/2-(ps[j][k]+2)*(k*(k-1)/2) : (ps[j][k]+1)*k*(ps[j][l]+1)*l);
								ndp[to] %= mod;
								ps[j][l]++;
							}
						}
						ps[j][k]++;
					}
				}
			}
			dp = ndp;
			w++;
		}
		while(w <= n*(n-1)/2){
			for(int j = 0;j < m;j++){
				int rem = 0;
				for(int k = 1;k <= n;k++){
					rem += (k*(k-1)/2-(k-1))*ps[j][k];
				}
				rem -= w-1-(n-1);
				if(rem > 0){
					dp[j] = dp[j] * rem % mod;
				}else{
					dp[j] = 0;
				}
			}
			w++;
		}
		out.println(dp[m-1]);
	}
	
	static long h(int[] a)
	{
		long h = 0;
		for(int j = 0;j < a.length;j++){
			h = h * 1000000009 + a[j];
		}
		return h;
	}
	
	public static int[][][] enumPartitions(int n)
	{
		int[][][] dp = new int[n+1][][];
		
		dp[1] = new int[][]{{0, 1}};
		for(int i = 2;i <= n;i++){
			dp[i] = new int[6000][];
			int f = 0;
			Set<Integer> hset = new HashSet<Integer>();
			for(int[] r : dp[i-1]){
				int[] nex = Arrays.copyOf(r, i+1);
				for(int j = 0;j <= i-1;j++){
					if(j > 0 && nex[j] == 0)continue;
					if(j > 0)nex[j]--;
					nex[j+1]++;
					int h = Arrays.hashCode(nex);
					if(!hset.contains(h)){
						dp[i][f++] = Arrays.copyOf(nex, i+1);
						hset.add(h);
					}
					if(j > 0)nex[j]++;
					nex[j+1]--;
				}
			}
			dp[i] = Arrays.copyOf(dp[i], f);
		}
		return dp;
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