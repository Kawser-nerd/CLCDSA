import java.util.*;

public class Main {
	
	/*
	 * default function
	 * */	
	int ni() {
		return cin.nextInt();
	}
	
	String nl() {
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
		
		
		long res = solve();
		
		/*
		 * finish
		 */
		
		output = res +"";
		println(output);
			
	}
	/* 
	 * define variable
	 */
	
	int N, T;
	int[] times;
	
	void input() {
		N = ni();
		T = ni();
		
		times = new int[N];
		
		for (int i = 0; i < N; i ++) {
			times[i] = ni();
		}		
	}
	
	
	long solve() {
		//first push began at 0
		long sum   = T;
		long preEnd= T;
		
		for (int i = 1; i < N; i ++) {
			
			if (times[i] >= preEnd) {
				preEnd = times[i] + T;
				sum += T;
			}
			
			else {
				long diff = times[i] - times[i-1];
				preEnd += diff;
				sum += diff;
			}
		}
		
		return sum;
	}
	
}