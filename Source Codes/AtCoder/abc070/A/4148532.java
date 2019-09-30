import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		System.out.println((n / 100 == n % 10) ? "Yes" : "No");

		sc.close();


	}

}