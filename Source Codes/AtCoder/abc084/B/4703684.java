import java.io.*;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int[] nums = Arrays.stream(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		String postalCode = stdin.readLine();
		String regexp = "[0-9]{" + nums[0] + "}-[0-9]{"+ nums[1] + "}";
		String answer = postalCode.matches(regexp) ? "Yes" : "No";
		System.out.println(answer);
	}
}