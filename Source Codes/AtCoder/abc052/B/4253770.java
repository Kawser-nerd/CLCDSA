import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String str = sc.next();
		int x = 0;
		int[] nums = new int[n];
		String[] strs = str.split("");
		for(int i=0; i<strs.length; i++) {
			if(strs[i].equals("I")) {
				x += 1;
				nums[i] = x;
			}else if(strs[i].equals("D")) {
				x -= 1;	
				nums[i] = x;
			}
		}
		int max = Integer.MIN_VALUE;
		for(int i=0; i<nums.length; i++) {
			max = Math.max(max, nums[i]);
		}
		if(max < 0) {
			System.out.println(0);
		}else {
			System.out.println(max);
		}
	}
}