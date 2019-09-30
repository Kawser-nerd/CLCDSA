import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni(), m = ni();
		int[][] es = new int[m][];
		int[] ep = new int[n];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1};
			ep[es[i][0]]++;
			ep[es[i][1]]++;
		}
		int[][] oppos = new int[n][];
		int[][] times = new int[n][];
		for(int i = 0;i < n;i++){
			oppos[i] = new int[ep[i]];
			times[i] = new int[ep[i]];
		}
		Arrays.fill(ep, 0);
		for(int i = 0;i < m;i++){
			oppos[es[i][0]][ep[es[i][0]]] = es[i][1];
			times[es[i][0]][ep[es[i][0]]++] = i;
			oppos[es[i][1]][ep[es[i][1]]] = es[i][0];
			times[es[i][1]][ep[es[i][1]]++] = i;
		}
		
		boolean[][] sacrifice = new boolean[n][n];
		boolean[] dead = new boolean[n];
		outer:
		for(int i = 0;i < n;i++){
			int[] alive = new int[n];
			Arrays.fill(alive, -1);
			alive[i] = m+100;
			Queue<Integer> q = new ArrayDeque<>();
			q.add(i);
			while(!q.isEmpty()){
				int cur = q.poll();
				sacrifice[i][cur] = true;
				int time = Arrays.binarySearch(times[cur], alive[cur]-1);
				if(time < 0)time = -time-2;
				for(int j = time;j >= 0;j--){
					if(alive[oppos[cur][j]] != -1){
						dead[i] = true;
						continue outer;
					}
					alive[oppos[cur][j]] = times[cur][j];
					q.add(oppos[cur][j]);
				}
			}
		}
		
		int ans = 0;
		for(int i = 0;i < n;i++){
			inner:
			for(int j = i+1;j < n;j++){
				if(dead[i] || dead[j])continue;
				for(int k = 0;k < n;k++){
					if(sacrifice[i][k] && sacrifice[j][k])continue inner;
				}
				ans++;
			}
		}
		out.println(ans);
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