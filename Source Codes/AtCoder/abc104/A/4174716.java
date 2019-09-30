import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int r = sc.nextInt();

		System.out.println(r < 1200 ? "ABC" : r < 2800 ? "ARC" : "AGC");

		sc.close();

	}
}