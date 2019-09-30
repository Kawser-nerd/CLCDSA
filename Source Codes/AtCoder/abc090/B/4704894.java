import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int[] input = Arrays.stream(stdin.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		long ans = IntStream.rangeClosed(input[0], input[1])
				.mapToObj(String::valueOf)
				.filter(s -> s.equals((new StringBuilder(s)).reverse().toString()))
				.count();
		System.out.println(ans);
	}

}