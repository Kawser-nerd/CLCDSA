import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int C = reader.nextInt();
		int safe = A + B;
		int danger = C;
		int ans = Math.min(safe + 1, danger);
		ans += B;

		reader.close();
		System.out.print(ans);
	}
}