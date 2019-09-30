import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int C = reader.nextInt();
		String ans = "Yes";
		if (A + B < C) {
			ans = "No";
		}

		System.out.println(ans);
		reader.close();
	}
}