import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

		String line = input.readLine();
		int n = Integer.parseInt(line);

		System.out.println((n % 2 == 0)?n:n*2);
	}
}