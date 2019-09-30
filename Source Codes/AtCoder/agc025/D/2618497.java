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
	
	static int[][] neis(int D)
	{
		int[][] ret = new int[1000][];
		int p = 0;
		for(int i = -(int)Math.sqrt(D);i <= (int)Math.sqrt(D);i++){
			int j = (int)Math.sqrt(D-i*i);
			if(i*i+j*j == D){
				ret[p++] = new int[]{i, j};
				ret[p++] = new int[]{i, -j};
			}
		}
		return Arrays.copyOf(ret, p);
	}
	
	static void solve()
	{
		int n = ni(), D1 = ni(), D2 = ni();
		int[][] c1 = paint(2*n, D1, neis(D1));
		int[][] c2 = paint(2*n, D2, neis(D2));
		
		int[][] f = new int[2][2];
		for(int i = 0;i < 2*n;i++){
			for(int j = 0;j < 2*n;j++){
				f[c1[i][j]][c2[i][j]]++;
			}
		}
		for(int i = 0;i < 2;i++){
			for(int j = 0;j < 2;j++){
				if(f[i][j] >= n*n){
					int rem = n*n;
					for(int x = 0;x < 2*n;x++){
						for(int y = 0;y < 2*n;y++){
							if(c1[x][y] == i && c2[x][y] == j && --rem >= 0){
								out.println(x + " " + y);
							}
						}
					}
					return;
				}
			}
		}
	}
	
	static int[][] paint(int n, int d, int[][] neis)
	{
		int[][] color = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(color[i], -1);
		}
		Queue<int[]> q = new ArrayDeque<>();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(color[i][j] == -1){
					q.add(new int[]{i, j});
					color[i][j] = 0;
					while(!q.isEmpty()){
						int[] cur = q.poll();
						int x = cur[0], y = cur[1];
						for(int[] nei : neis){
							int nx = x + nei[0], ny = y + nei[1];
							if(nx >= 0 && nx < n && ny >= 0 && ny < n && color[nx][ny] == -1){
								color[nx][ny] = color[x][y] ^ 1;
								q.add(new int[]{nx, ny});
							}
						}
					}
				}
			}
		}
		return color;
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