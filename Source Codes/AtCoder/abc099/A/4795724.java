import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		String ans = "ABD";
		if (N < 1000) {
			ans = "ABC";
		}
		

		System.out.print(ans);
		reader.close();
	}
}