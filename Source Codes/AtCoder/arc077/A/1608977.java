import java.util.*;

// ARC 77-C
// http://arc077.contest.atcoder.jp/tasks/arc077_a

public class Main {
	
	public static void main (String[] args) throws InterruptedException {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		int[] nums = new int[N];
		
		for (int i = 0; i < N; i++) {
			nums[i] = in.nextInt();
		}
		
		int index = N - 1;
		StringBuilder s = new StringBuilder();
		while (index >= 0) {
			s.append(nums[index] + " ");
			index -= 2;
		}
		index = N % 2;
		while (index < N) {
			s.append(nums[index] + " ");
			index += 2;
		}
		System.out.println(s);
	}
	
}