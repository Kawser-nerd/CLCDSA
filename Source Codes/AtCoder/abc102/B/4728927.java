import java.io.*;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		stdin.readLine();
		int[] nums = Arrays.stream(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		Arrays.sort(nums);
		System.out.println(nums[nums.length-1] - nums[0]);
	}

}