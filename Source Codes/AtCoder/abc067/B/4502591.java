import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] nums = new int[n];
		int ans = 0;

		for(int i=0; i<nums.length; i++) {
			nums[i] = sc.nextInt();
		}

		Arrays.sort(nums);
			for(int j=1; j<k+1; j++) {
				ans += nums[nums.length-j];
			}
			System.out.println(ans);
	}
}