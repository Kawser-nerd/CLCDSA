import java.io.*;
import java.util.stream.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int[] inputs = Stream.of(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		int ans = 0;
		for(int i = 0; i <= inputs[0];i++) {
			int sum = Stream.of(String.valueOf(i).split("")).mapToInt(Integer::parseInt).sum();
			if(inputs[1] <= sum && sum <= inputs[2]) ans += i; 
		}
		System.out.println(ans);
	}
}