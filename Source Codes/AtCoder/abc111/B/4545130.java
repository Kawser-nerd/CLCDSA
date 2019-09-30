import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int i = 1;
		for (; i <= 9; i++) {
			if (n <= i * 111) {
				break;
			}
		}
		System.out.println(i * 111);
		sc.close();
	}
}