import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long x = sc.nextInt();
		int cnt = 0;
		
		long[] nums = new long [N];
		long sum = 0;
		for(int i=0; i<N; i++) {
			nums[i] = sc.nextLong();
			sum += nums[i];
		}
		Arrays.sort(nums);
		
		if (x>sum) {
			System.out.println(N - 1);
		} else if (x == sum ) {
			System.out.println(N);
		} else {
			for(int i=0; i<N; i++) {
				if(nums[i] <= x) {
					x = x - nums[i];
					cnt++;
				}
			}
			System.out.println(cnt);
		}
		
	}
	
}