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
		
		
		
		solve();
		
		/*
		 * finish
		 */
		
		output = cnt+"";
		println(output);
			
	}
	/* 
	 * define variable
	 */
	
	
	int N;
	int[] nums;
	long cnt;
	
	void input() {
		
		cnt = 0;
		
		N = ni();
		nums = new int[N];
		
		for (int i = 0; i < N; i ++) {
			nums[i] = ni();
		}
	}
	
	void solve() {
		
		long sum1 = 0, sum2 = 0;
		long cnt1 = 0, cnt2 = 0;
		
		if (nums[0] > 0) {
			
			sum1 = nums[0];
			cnt2 += nums[0] + 1;
			sum2 = -1;
		} else if (nums[0] == 0) {
			
			sum1 = 1;
			cnt1 += 1;
			sum2 = -1;
			cnt2 += 1;
		} else {
			
			sum1 = nums[0];
			cnt2 = Math.abs(nums[0]) + 1;
			sum2 = 1;
		}
		
		//1th iteration
		for (int i = 1; i < N; i ++) {
			
			if (sum1 > 0) {
				
				if (sum1 + nums[i] >= 0) {
					cnt1 += sum1 + nums[i] + 1;
					sum1 = -1;					
				} else {
					sum1 = sum1 + nums[i];
				}
			} else{
				
				if (sum1 + nums[i] <= 0) {
					cnt1 += Math.abs(sum1 + nums[i]) + 1;
					sum1 = 1;
				} else {
					sum1 = sum1 + nums[i];
				}
			}
		}
		if (sum1 == 0) {
			cnt1 += 1;
		}
		
		
		//2nd iteration
		for (int i = 1; i < N; i ++) {

			if (sum2 > 0) {
				
				if (sum2 + nums[i] >= 0) {
					cnt2 += sum2 + nums[i] + 1;
					sum2 = -1;					
				} else {
					sum2 = sum2 + nums[i];
				}
			} else{
				
				if (sum2 + nums[i] <= 0) {
					cnt2 += Math.abs(sum2 + nums[i]) + 1;
					sum2 = 1;
				} else {
					sum2 = sum2 + nums[i];
				}
			}
		}
		
		if (sum2 == 0) {
			cnt2 += 1;
		}
		
		
		cnt = Math.min(cnt1, cnt2);
	}
}