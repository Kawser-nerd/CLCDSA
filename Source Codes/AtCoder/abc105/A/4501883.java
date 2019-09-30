import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int K = reader.nextInt();
		int ans = 0;
		if (N % K > 0) {
			ans = 1;
		}

		reader.close();
		System.out.print(ans);
	}
}