import java.util.*;

// ARC 95-D
// https://beta.atcoder.jp/contests/arc095/tasks/arc095_b

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int N = in.nextInt();

		int[] nums = new int[N];
		for (int i = 0; i < N; i++) {
			nums[i] = in.nextInt();
		}
		
		Arrays.sort(nums);
	
		int n = nums[N - 1];
		int r = nums[0];
		
		for (int i = 1; i < N; i++) {
			if (Math.abs(nums[i] - n / 2.0) < Math.abs(r - n / 2.0)) {
				r = nums[i];
			}
		}
		
		System.out.printf("%d %d\n", n, r);
	}
}