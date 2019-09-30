import java.io.*;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException{
		String str = new BufferedReader(new InputStreamReader(System.in)).readLine();
		int[] input = Arrays.stream(str.split(" ")).mapToInt(Integer::parseInt).toArray();
		System.out.println((int)((input[1]+input[1]/100)* Math.pow(100, input[0])));
	}

}