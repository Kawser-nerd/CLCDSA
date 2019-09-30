import java.io.*;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		String str = new BufferedReader(new InputStreamReader(System.in)).readLine();
		int num = Integer.parseInt(str);
		int sum = Arrays.stream(str.split("")).mapToInt(Integer::parseInt).sum();
		String ans = num % sum == 0 ? "Yes" : "No";
		System.out.println(ans);
	}
}