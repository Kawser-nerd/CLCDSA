import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		System.out.println(s.matches("A[a-z]+C[a-z]+") ? "AC" : "WA");

		sc.close();
	}
}