import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int ans = N;
		if (N % 2 == 1) {
			ans *= 2;
		}

		reader.close();
		System.out.print(ans);
	}
}