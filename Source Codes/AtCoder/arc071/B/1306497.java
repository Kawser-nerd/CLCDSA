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
			
		input();
		/* 
		 * start
		 */	
		
		int res = solve();
		
		/*
		 * finish
		 */
		
		output = res +"";
		println(output);
			
	}
	/* 
	 * define variable
	 */
	
	int n, m;
	long[] x;
	long[] y;
	
	void input() {
		
		n = ni();
		m = ni();
		x = new long[n];
		y = new long[m];
		
		for (int i = 0; i < n; i ++) {
			x[i] = nl();
		}
		
		for (int j = 0; j < m; j ++) {
			y[j] = nl();
		}
	}
	
	int solve() {
		
		long xsum = 0, ysum = 0;
		
		for (int i = 0; i < n; i ++) {
			xsum += x[i] * i - x[i] * (n-i-1);
			xsum %= MOD;			
		}
		
		for (int i = 0; i < m; i ++) {
			ysum += y[i] * i - y[i] * (m-i-1);
			ysum %= MOD;
		}		
		
		return (int)((xsum * ysum)%MOD);
	}
	
}