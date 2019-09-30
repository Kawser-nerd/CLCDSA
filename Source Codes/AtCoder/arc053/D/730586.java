import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static class LS extends ArrayList<State>
	{
	}
	
	static class State
	{
		int[] set;
		long v;
		
		public State(int[] set, long v) {
			this.set = set;
			this.v = v;
		}
	};
	
	static void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] b = na(n);
		for(int i = 0;i < n;i++)a[i]--;
		for(int i = 0;i < n;i++)b[i]--;
		LS[] pre = new LS[n];
		LS[] cur = new LS[n]; // [last]
		{
			pre[0] = new LS();
			pre[0].add(new State(new int[]{0}, 1L));
		}
		int mod = 1000000007;
//		long[] temp = new long[s.set.length*2];
		long[] temp = new long[10];
		for(int i = 0;i < 2*n-2;i++){
			Arrays.fill(cur, null);
			for(int j = 0;j < n;j++){ // len=i, last=j
				if(pre[j] == null)continue;
				for(State s : pre[j]){
					int p = 0;
					for(int r : s.set){
						int c = i-r;
						if(r < n-1)temp[p++] = (long)b[c]<<32|r+1;
						if(c < n-1)temp[p++] = (long)a[r]<<32|r;
					}
					Arrays.sort(temp, 0, p);
					for(int k = 0;k < p;){
						int l = k;
						while(l < p && temp[k]>>>32 == temp[l]>>>32)l++;
						int[] lset = new int[l-k];
						// uniq
						int q = 0;
						for(int u = k;u < l;u++){
							if(u > k && temp[u] == temp[u-1])continue;
							lset[q++] = (int)temp[u];
						}
						lset = Arrays.copyOf(lset, q);
						
						int nj = (int)(temp[k]>>>32);
						if(cur[nj] == null)cur[nj] = new LS();
						boolean found = false;
						for(State ts : cur[nj]){
							if(Arrays.equals(ts.set, lset)){
								ts.v += s.v;
								if(ts.v >= mod)ts.v -= mod;
								found = true;
								break;
							}
						}
						if(!found){
							cur[nj].add(new State(lset, s.v));
						}
						
						k = l;
					}

				}
			}
			LS[] dum = pre; pre = cur; cur = dum;
		}
		
		long ret = 0;
		for(LS ls : pre){
			if(ls != null){
				for(State s : ls)ret += s.v;
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