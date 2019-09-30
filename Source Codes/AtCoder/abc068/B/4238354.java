import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int count = 0;
		while ((int) Math.pow(2, count) <= n) {
			count++;
		}
		System.out.println((int)Math.pow(2, count - 1));

		sc.close();
	}
}