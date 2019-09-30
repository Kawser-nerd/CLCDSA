import java.io.*;
import java.util.*;
 
public class Main{
	
	int H, W, K;
	int[][] flg;
	int[] dh = {1, 0, -1, 0};
	int[] dw =  {0, 1, 0, -1};
	
	public void solve(){
		H = nextInt();
		W = nextInt();
		K = nextInt();
		
		flg = new int[H][W];

		int h = 0, w = 0;
		for(int i = 0; i < H; i++){
			String str = next();
			for(int j = 0; j < W; j++){
				if(str.charAt(j) == '#'){
					flg[i][j] += 2;
				}else if(str.charAt(j) == 'S'){
					h = i;
					w = j;
				}
			}
		}
		Queue<Pair> queue = new ArrayDeque<>();
		int[][] count = new int[H][W];
		count[h][w] = 1;
		queue.offer(new Pair(h, w));
		
		int mind = H * W;
		
		while(!queue.isEmpty()){
			Pair p = queue.poll();
			int cnt = count[p.h][p.w] - 1;
			mind = Math.min(mind, dis(p.h, p.w));
			if(cnt < K){
				for(int i = 0; i < 4; i++){
					int hh = p.h + dh[i];
					int ww = p.w + dw[i];
					if(0 <= hh && hh < H && 0 <= ww && ww < W &&
						count[hh][ww] == 0 && flg[hh][ww] == 0){
						count[hh][ww] = cnt + 2;
						queue.offer(new Pair(hh, ww));
					}
				}
			}
		}
		//if(mind == 0) mind = 1;
		out.println((mind + K - 1) / K + 1);
	}
	
	int dis(int h, int w){
		int ret = Math.min(h,  w);
		ret = Math.min(ret, H - h - 1);
		ret = Math.min(ret, (W - 1 - w));
		return ret;
	}
	
	class Pair{
		int h;
		int w;
		public Pair(int h, int w){
			this.h = h;
			this.w = w;
		}
		
		
	}
	
	private static PrintWriter out;
	public static void main(String[] args){
		out = new PrintWriter(System.out);
		new Main().solve();
		out.flush();
	}
	
	
	
	public static int nextInt(){
		int num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if(str.charAt(0) == '-'){
			minus = true;
			i++;
		}
		int len = str.length();
		for(;i < len; i++){
			char c = str.charAt(i);
			if(!('0' <= c && c <= '9')) throw new RuntimeException();
			num = num * 10 + (c - '0');
		}
		return minus ? -num : num;
	}
	
	public static long nextLong(){
		long num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if(str.charAt(0) == '-'){
			minus = true;
			i++;
		}
		int len = str.length();
		for(;i < len; i++){
			char c = str.charAt(i);
			if(!('0' <= c && c <= '9')) throw new RuntimeException();
			num = num * 10l + (c - '0');
		}
		return minus ? -num : num;
	}
	public static String next(){
		int c;
		while(!isAlNum(c = read())){}
		StringBuilder build = new StringBuilder();
		build.append((char)c);
		while(isAlNum(c = read())){
			build.append((char)c);
		}
		return build.toString();
	}
	
	
	private static byte[] inputBuffer = new byte[1024];
	private static int bufferLength = 0;
	private static int bufferIndex = 0;
	private static int read(){
		if(bufferLength < 0) throw new RuntimeException();
		if(bufferIndex >= bufferLength){
			try{
				bufferLength = System.in.read(inputBuffer);
				bufferIndex = 0;
			}catch(IOException e){
				throw new RuntimeException(e);
			}
			if(bufferLength <= 0) return (bufferLength = -1);
		}
		return inputBuffer[bufferIndex++];
	}
	
	private static boolean isAlNum(int c){
		return '!' <= c && c <= '~';
	}
}