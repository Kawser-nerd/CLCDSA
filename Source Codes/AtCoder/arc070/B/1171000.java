import java.io.*;
import java.util.*;
import java.util.function.IntPredicate;
 
public class Main{
	int N, K;
	int[] A;
	public void solve(){
		N = nextInt();
		K = nextInt();
		A = new int[N];
		for(int i = 0; i < N; i++){
			A[i] = nextInt();
		}
		int ans = 0;
		boolean[][] a1 = new boolean[N][K];
		boolean[][] a2 = new boolean[N][K];
 
 
		a1[0][0] = true;
		for(int i = 0; i < N - 1; i++){
			for(int j = 0; j < K; j++){
				if(a1[i][j]){
					a1[i + 1][j] = true;
					if(j + A[i] < K){
						a1[i + 1][j + A[i]] = true;
					}
				}
			}
		}
		
		a2[N - 1][0] = true;
		for(int i = N - 1; i > 0; i--){
			for(int j = 0; j < K; j++){
				if(a2[i][j]){
					a2[i - 1][j] = true;
					if(j + A[i] < K){
						a2[i - 1][j + A[i]] = true;
					}
				}
			}
		}
		
 
		int[][] bit2 = new int[N][K + 1];
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < K; j++){
				bit2[i][j + 1] = bit2[i][j];
				if(a2[i][j]){
					bit2[i][j + 1]++;
				}
			}
		}
		
		
		for(int i = 0; i < N; i++){
			if(A[i] >= K) continue;
			int kk = K - A[i];
			boolean flg = false;
			for(int j = 0; j < K; j++){
				if(a1[i][j]){
					if(bit2[i][K - j] - bit2[i][Math.max(kk - j, 0)] > 0){
						flg = true;
						break;
					}
				}
			}
			if(!flg){
				ans++;
			}
		}
		out.println(ans);
		
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