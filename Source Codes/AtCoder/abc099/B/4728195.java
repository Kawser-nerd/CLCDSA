import java.io.*;
import java.util.Arrays;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) throws IOException {
		String input = (new BufferedReader(new InputStreamReader(System.in))).readLine();
		int[] highs = Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray();
		int diff = highs[1] - highs[0];
		int higher = IntStream.rangeClosed(1, diff).sum();
		System.out.println(higher - highs[1]);
	}

}