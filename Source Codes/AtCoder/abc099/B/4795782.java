import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int gap = B - A;
		int ans = -A;
		for (int i = 1; i < gap; i++) {
			ans += i;
		}

		System.out.print(ans);
		reader.close();
	}
}