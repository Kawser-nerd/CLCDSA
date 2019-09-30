import java.io.*;
import java.util.*;

 
public class Main{
	int N;
	int[] A;
	public void solve(){
		N = nextInt();
		A = new int[N];
		for(int i = 0; i < N; i++){
			A[i] = nextInt();
		}
		int[] cnt = new int[N];
		int max = 0;
		for(int i = 0; i < N; i++){
			cnt[A[i]]++;
			max = Math.max(max, A[i]);
		}
		if(max == 1){
			if(N == 2){
				out.println("Possible");
				return;
			}else{
				out.println("Impossible");
				return;
			}
		}else{
			for(int i = max; i >= max / 2 + 1; i--){
				if(cnt[i] < 2){
					out.println("Impossible");
					return;
				}
			}
			if(max % 2 == 0 && cnt[max / 2] != 1){
				out.println("Impossible");
				return;
			}
			if(max % 2 == 1 && cnt[(max + 1) / 2] != 2){
				out.println("Impossible");
				return;
			}
			for(int i = (max + 1) / 2 - 1; i > 0; i--){
				if(cnt[i] > 0){
					out.println("Impossible");
					return;
				}
			}
			out.println("Possible");
			return;
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