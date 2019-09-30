import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int K = reader.nextInt();
		String ans = ":(";
		if (N <= 8 && K <=8) {
			ans = "Yay!";
		}
		System.out.print(ans);
		reader.close();
	}
}