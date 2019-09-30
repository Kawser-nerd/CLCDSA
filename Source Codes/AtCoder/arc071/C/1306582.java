import java.util.*;

public class Main {
	
	/*
	 * default function
	 * */	
	int ni() {
		return cin.nextInt();
	}
	
	long nl() {
		return cin.nextLong();
	}
	
	String line() {
		return cin.nextLine();
	}
	
	void println(String str) {	
		System.out.println(str);
	}
	
	void print(String str) {
		System.out.print(str);
	}
	
	/*
	 * default variable
	 */
	
	static final int MOD = 1000000007;
	
	Scanner cin = new Scanner(System.in);	
	String  output;
	
	public static void main(String[] args) {			
		new Main().run();						
	}
	
	/* default above */		
	public void run() {
			
		
		/* 
		 * start
		 */	
		
		solve();
		
		/*
		 * finish
		 */
		
		
			
	}
	/* 
	 * define variable
	 */
	
	String S;
	String T;
	int N;
	
	void solve() {
		
		S = line();
		T = line();
		
		int[] sums = new int[S.length() + 1];
		int[] sumt = new int[T.length() + 1];
		
		sums[1] = S.charAt(0) - 'A' + 1;
		for (int i = 1; i < S.length(); i ++) {
			sums[i+1] = sums[i] + S.charAt(i) - 'A' + 1;
		}
		
		sumt[1] = T.charAt(0) - 'A' + 1;
		for (int i = 1; i < T.length(); i ++) {
			sumt[i+1] = sumt[i] + T.charAt(i) - 'A' + 1;
		}
				
		
		
		N = ni();
		
		for (int i = 0; i < N; i ++) {
			
			int a = ni();
			int b = ni();
			int c = ni();
			int d = ni();
			
			if ((sums[b] - sums[a-1]) % 3 == (sumt[d] - sumt[c-1]) % 3) {
				println("YES");
			} else {
				println("NO");
			}
			
		}
		
	}
	
	
	
}