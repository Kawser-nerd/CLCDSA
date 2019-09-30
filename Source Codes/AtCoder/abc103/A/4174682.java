import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a1 = sc.nextInt();
		int a2 = sc.nextInt();
		int a3 = sc.nextInt();

		System.out.println(Math.max(Math.max(Math.abs(a1 - a2), Math.abs(a2 - a3)), Math.abs(a3 - a1)));

		sc.close();

	}
}