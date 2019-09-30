import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		String result = "";
		if (N == 1) {
			result = "Hello World";
		} else {
			int A = reader.nextInt();
			int B = reader.nextInt();
			result = Integer.toString(A + B);
		}


		reader.close();
		System.out.print(result);
	}
}