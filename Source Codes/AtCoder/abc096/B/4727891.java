import java.io.*;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int[] nums = Arrays.stream(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		int time = Integer.parseInt(stdin.readLine());
		Arrays.sort(nums);
		nums[2] *= (int)Math.pow(2, time);
		System.out.println(Arrays.stream(nums).sum());
	}

}