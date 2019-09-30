import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] a) throws IOException {
		System.out.println(new BufferedReader(new InputStreamReader(System.in)).readLine().contains("9")?"Yes":"No");
	}
}