import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int D = reader.nextInt();
		int X = reader.nextInt();
		int ans = X;
		for (int i = 1; i <= N; i++) {
			int num = reader.nextInt();
			ans += (D - 1) / num + 1;
		}
		System.out.print(ans);
	}
}