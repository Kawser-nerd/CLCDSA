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
		int[] a = na(n);
		int[] b = na(n);
		for(int i = 0;i < n;i++)a[i]--;
		for(int i = 0;i < n;i++)b[i]--;
		int[][] pre = new int[n][4];
		int[][] cur = new int[n][4]; // [last][last pos set index]
		int[][] preh = new int[n][4];
		int[][] curh = new int[n][4]; // hash
		int[][] presz = new int[n][4];
		int[][] cursz = new int[n][4]; // set's size
		int[] prep = new int[n];
		int[] curp = new int[n];
		
		pre[0][0] = 1;
		prep[0] = 1;
		presz[0][0] = 1;
		int mod = 1000000007;
		long[] temp = new long[10];
		for(int i = 0;i < 2*n-2;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < curp[j];k++){
					cur[j][k] = curh[j][k] = cursz[j][k] = 0;
				}
				curp[j] = 0;
			}
			for(int j = 0;j < n;j++){ // len=i, last=j
				for(int f = 0;f < prep[j];f++){
					int p = 0;
					for(int sh = 0, h = preh[j][f];sh < presz[j][f];sh++,h>>>=16){
						int r = h&65535;
						int c = i-r;
						if(r < n-1)temp[p++] = (long)b[c]<<32|r+1;
						if(c < n-1)temp[p++] = (long)a[r]<<32|r;
					}
					Arrays.sort(temp, 0, p);
					for(int k = 0;k < p;){
						int l = k;
						while(l < p && temp[k]>>>32 == temp[l]>>>32)l++;
						// uniq
						int q = 0;
						int lh = 0;
						for(int u = k;u < l;u++){
							if(u > k && temp[u] == temp[u-1])continue;
							lh = lh<<16|(int)temp[u];
							q++;
						}
						
						int nj = (int)(temp[k]>>>32);
						boolean found = false;
						for(int g = 0;g < curp[nj];g++){
							if(curh[nj][g] == lh && cursz[nj][g] == q){
								cur[nj][g] += pre[j][f];
								if(cur[nj][g] >= mod)cur[nj][g] -= mod;
								found = true;
								break;
							}
						}
						if(!found){
							cur[nj][curp[nj]] = pre[j][f];
							curh[nj][curp[nj]] = lh;
							cursz[nj][curp[nj]] = q;
							curp[nj]++;
						}
						
						k = l;
					}

				}
			}
			{int[][] dum = pre; pre = cur; cur = dum;}
			{int[][] dum = preh; preh = curh; curh = dum;}
			{int[][] dum = presz; presz = cursz; cursz = dum;}
			{int[] dum = prep; prep = curp; curp = dum;}
		}
		
		long ret = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < prep[i];j++){
				ret += pre[i][j];
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