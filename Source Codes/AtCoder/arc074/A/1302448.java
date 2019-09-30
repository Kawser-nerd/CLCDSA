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
	
	int H, W;
	
	void input() {
		H = ni();
		W = ni();
		
		if (W > H) {
			W = H + W;
			H = W - H;
			W = W - H;
		}
	}
	
	int solve() {
		
		if (H % 3 == 0 || W % 3 == 0) {
			return 0;
		}
		
		return Math.min(cal(H, W), cal(W, H));		
	}
	
	int cal(long h, long w) {
		
		long res = Long.MAX_VALUE;
		
		res = Math.min(res, W);
		
		for (long i = h/3; i <= h/2; i ++) {
			long a[] = new long[3];
			
			a[0] = (i) * w;
			a[1] = (h - i) * (w / 2);
			a[2] = (h - i) * (w - w/2);
			Arrays.sort(a);
			res = Math.min(res, a[2] - a[0]);		
		}
		return (int)res;
	}
	
	
}