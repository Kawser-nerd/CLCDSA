import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n =ni(), m = ni();
		int[][] cond = new int[m][];
		for(int i = 0;i < m;i++){
			cond[i] = new int[]{ni()-1, ni()-1, ni()};
		}
		Arrays.sort(cond, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});

		int mod = 1000000007;
		long[][] dp = new long[n+1][n+1]; // len1,len<=2
		dp[0][0] = 1;
		int p = 0;
		for(int i = 0;i < n;i++){
			long[][] ndp = new long[n+1][n+1];
			int[] maxs = new int[4];
			int[] mins = new int[4];
			Arrays.fill(maxs, -1);
			Arrays.fill(mins, 9999);
			while(p < m && cond[p][1] <= i){
				maxs[cond[p][2]] = Math.max(maxs[cond[p][2]], cond[p][1] - cond[p][0] + 1);
				mins[cond[p][2]] = Math.min(mins[cond[p][2]], cond[p][1] - cond[p][0] + 1);
				p++;
			}
			
			for(int j = 0;j <= n;j++){
				for(int k = j;k <= n;k++){
					if(dp[j][k] == 0)continue;
					// 1
					{
						int nj = j+1, nk = k+1;
						if(maxs[1] == -1 || maxs[1] <= nj){
							if(maxs[2] == -1 || nj+1 <= mins[2] && maxs[2] <= nk){
								if(maxs[3] == -1 || nk+1 <= mins[3]){
									ndp[nj][nk] += dp[j][k];
									if(ndp[nj][nk] >= mod)ndp[nj][nk] -= mod;
								}
							}
						}
					}
					// 2
					{
						int nj = 1, nk = k+1;
						if(maxs[1] == -1 || maxs[1] <= nj){
							if(maxs[2] == -1 || nj+1 <= mins[2] && maxs[2] <= nk){
								if(maxs[3] == -1 || nk+1 <= mins[3]){
									ndp[nj][nk] += dp[j][k];
									if(ndp[nj][nk] >= mod)ndp[nj][nk] -= mod;
								}
							}
						}
					}
					// 3
					{
						int nj = 1, nk = j+1;
						if(maxs[1] == -1 || maxs[1] <= nj){
							if(maxs[2] == -1 || nj+1 <= mins[2] && maxs[2] <= nk){
								if(maxs[3] == -1 || nk+1 <= mins[3]){
									ndp[nj][nk] += dp[j][k];
									if(ndp[nj][nk] >= mod)ndp[nj][nk] -= mod;
								}
							}
						}
					}
				}
			}
			dp = ndp;
		}
		long ret = 0;
		for(int j = 0;j <= n;j++){
			for(int k = j;k <= n;k++){
				ret += dp[j][k];
			}
		}
		out.println(ret%mod);
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