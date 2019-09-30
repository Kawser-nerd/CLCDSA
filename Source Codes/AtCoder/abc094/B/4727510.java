import java.io.*;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int[] inputs = Arrays.stream(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		int[] fee = Arrays.stream(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		long left = Arrays.stream(fee).filter(i -> i < inputs[2]).count();
		long right = Arrays.stream(fee).filter(i -> i > inputs[2]).count();
		System.out.println(Math.min(left, right));
	}

}