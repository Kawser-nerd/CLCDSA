import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();

		System.out.println(Math.abs(a - c) <= d ? "Yes"
							: Math.abs(a - b) <= d && Math.abs(b - c) <= d ? "Yes"
							: "No");

		sc.close();
	}

}