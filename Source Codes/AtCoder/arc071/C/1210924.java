import java.io.*;
import java.util.*;
import java.util.function.IntPredicate;
 
public class Main{
	String S, T;
	int[] sumS;
	int[] sumT;
	int Q;
	public void solve(){
		S = next();
		T = next();
		sumS = new int[S.length() + 1];
		sumT = new int[T.length() + 1];
		for(int i = 0; i < S.length(); i++){
			sumS[i + 1] = sumS[i] + ((S.charAt(i) == 'A') ? 1 : 0);
		}

		for(int i = 0; i < T.length(); i++){
			sumT[i + 1] = sumT[i] + ((T.charAt(i) == 'A') ? 1 : 0);
		}
		
		Q = nextInt();
		for(int i = 0; i < Q; i++){
			int a = nextInt() - 1;
			int b = nextInt();
			int c = nextInt() - 1;
			int d = nextInt();
			
			int sa = sumS[b] - sumS[a];
			int sb = b - a - sa;
			
			sa %= 3;
			sb %= 3;
			
			int ta = sumT[d] - sumT[c];
			int tb = d - c - ta;
			
			ta %= 3;
			tb %= 3;
			
			if(sa == ta && sb == tb){
				out.println("YES");
			}else if((sa + 1) % 3 == ta && (sb + 1) % 3 == tb){
				out.println("YES");
			}else if((sa + 2) % 3 == ta && (sb + 2) % 3 == tb){
				out.println("YES");
			}else{
				out.println("NO");
			}
			
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