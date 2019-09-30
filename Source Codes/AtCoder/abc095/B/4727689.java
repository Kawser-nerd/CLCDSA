import java.io.*;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int left_ingredient = Arrays.stream(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray()[1];
		int[] need_ingredient = stdin.lines().mapToInt(Integer::parseInt).toArray();
		int min = Arrays.stream(need_ingredient).min().getAsInt();
		int count = 0;
		for(int gram : need_ingredient) {
			left_ingredient -= gram;
			count++;
		}
		count += Math.floor(left_ingredient/min);
		System.out.println(count);
	}
}