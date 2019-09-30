import java.io.*;
import java.util.*;
import java.util.function.DoublePredicate;
import java.util.function.DoubleUnaryOperator;
 
public class Main{
	int mod = 1000000007;
	int X;
	int Y;
	int Z;
	int N;
	int[] sum;
	int[] pow10;
	int[][] dp;
	public void solve(){
		N = nextInt();
		X = nextInt();
		Y = nextInt();
		Z = nextInt();
		sum = new int[]{-1, X - 1, X + Y - 1, X + Y + Z - 1};
		dp = new int[N][1 << 18];
		for(int i = 0; i < N; i++){
			Arrays.fill(dp[i], -1);
		}
		
		pow10 = new int[N + 1];
		pow10[0] = 1;
		
		for(int i = 1; i < pow10.length; i++){
			pow10[i] = (int)((long)pow10[i - 1] * 10 % mod);
		}
		
		out.println(dfs(0, 0));
	}
	
	public int dfs(int n, int bit){
		String str = Integer.toBinaryString(bit);
		if(get(bit, 3, 0)){
			return pow10[N - n];
		}
		if(n == N){
			return 0;
		}
		if(dp[n][bit] != -1){
			return dp[n][bit];
		}
		int ans = 0;
		for(int i = 1; i <= 10; i++){
			int nb = 0;
			if(i <= X){
				nb = set(nb, 0, i);
			}
			for(int j = 1; j <= X; j++){
				if(get(bit, 0, j) && j + i <= X){
					nb = set(nb, 0, j + i);
				}
			}
			

			if(get(bit, 0, X) && i <= Y){
				nb = set(nb, 1, i);
			}
			
			for(int j = 1; j <= Y; j++){
				if(get(bit, 1, j) && j + i <= Y){
					nb = set(nb, 1, j + i);
				}
			}
			

			if(get(bit, 1, Y) && i <= Z){
				nb = set(nb, 2, i);
			}
			
			for(int j = 1; j <= Z; j++){
				if(get(bit, 2, j) && j + i <= Z){
					nb = set(nb, 2, j + i);
				}
			}
			ans = (ans + dfs(n + 1, nb)) % mod;
		}
		return dp[n][bit] = ans;
	}
	
	public boolean get(int bit, int t, int i){
		return (bit & 1 << (sum[t] + i)) != 0;
	}
	
	public int set(int bit, int t, int i){
		return bit | (1 << (sum[t] + i));
	}
	
	public int count(int num, int len){
		if(len == 1){
			if(0 < num && num <= 10){
				return 1;
			}else{
				return 0;
			}
		}
		if(num <= 0){
			return 0;
		}
		
		int ans = 0;
		for(int i = 1; i <= 10; i++){
			ans = (ans + count(num - i, len - 1)) % mod;
		}
		return ans;
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