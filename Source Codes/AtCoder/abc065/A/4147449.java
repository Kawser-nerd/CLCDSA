import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();

		System.out.println((b <= a) ? "delicious" : (b <= a + x) ? "safe" : "dangerous");

	}

}