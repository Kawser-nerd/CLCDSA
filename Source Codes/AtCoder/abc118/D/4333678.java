import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static int m;

	private static void solve(){
		//Implement solution here.
		n = ni();
		m = ni();
		int[] aary = na(m);
		Arrays.sort(aary);

		int[] mary = new int[]{-1,2,5,5,4,5,6,3,7,6};
		int[] cary = new int[m];
		for(int i = 0; i < m; i++){
			cary[i] = mary[aary[i]];
		}

		int[] dp = new int[n + 1];
		Arrays.fill(dp,Integer.MIN_VALUE);
		dp[0] = 0;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < m; j++){
				int before = i - cary[j];
				if(before >= 0){
					dp[i] = Math.max(dp[i],dp[before] + 1);
				}
			}
		}
		int rest = n;
		StringBuilder sb = new StringBuilder();
		for(int i = dp[n] ; i > 0; i--){
			for(int j = m - 1; j >= 0; j--){
				if(rest - mary[aary[j]] >= 0 && dp[rest - mary[aary[j]]] == i - 1){
					rest -= mary[aary[j]];
					sb.append(aary[j]);
					break;
				}
			}
		}
		System.out.println(sb.toString());
	}


	//Switch input source (stdin/file)
	private static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args){
		String debugDataPath = System.getenv("DD_PATH");        
		if(debugDataPath != null){
			try{
				scanner = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File(debugDataPath)))));
			}catch(Exception e){
				throw new RuntimeException(e);
			}
		}
		solve();
	}

	//Input read utility
	private static StringTokenizer tokenizer = null;
	public static String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(scanner.nextLine());
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}
	//Get next single int
	private static int ni() {
		return Integer.parseInt(next());
	}
	//Get next single long
	private static long nl() {
		return Long.parseLong(next());
	}
	//Get next single double
	private static double nd() {
		return Double.parseDouble(next());
	}
	//Get next int array from one line
	private static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}
	//Get next char array from one line
	private static char[] ns() {
		return next().toCharArray();
	}
	//Get next long array from one line
	private static long[] nal(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nl();
		return a;
	}
}