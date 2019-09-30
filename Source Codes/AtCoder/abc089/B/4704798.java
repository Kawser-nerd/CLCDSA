import java.io.*;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		stdin.readLine();
		long cnt = Arrays.stream(stdin.readLine().split(" ")).sorted().distinct().count();
		String ans = cnt == 3 ? "Three" : "Four";
		System.out.println(ans);
	}

}