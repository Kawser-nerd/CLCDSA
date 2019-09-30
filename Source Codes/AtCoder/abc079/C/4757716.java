import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		sc.close();

		int a = str.charAt(0) - '0';
		int b = str.charAt(1) - '0';
		int c = str.charAt(2) - '0';
		int d = str.charAt(3) - '0';
		if (a + b + c + d == 7) {
			System.out.println(a + "+" + b + "+" + c + "+" + d + "=7");
			return;
		}
		if (a + b + c - d == 7) {
			System.out.println(a + "+" + b + "+" + c + "-" + d + "=7");
			return;
		}
		if (a + b - c + d == 7) {
			System.out.println(a + "+" + b + "-" + c + "+" + d + "=7");
			return;
		}
		if (a - b + c + d == 7) {
			System.out.println(a + "-" + b + "+" + c + "+" + d + "=7");
			return;
		}
		if (a + b - c - d == 7) {
			System.out.println(a + "+" + b + "-" + c + "-" + d + "=7");
			return;
		}
		if (a - b + c - d == 7) {
			System.out.println(a + "-" + b + "+" + c + "-" + d + "=7");
			return;
		}
		if (a - b - c + d == 7) {
			System.out.println(a + "-" + b + "-" + c + "+" + d + "=7");
			return;
		}
		if (a - b - c - d == 7) {
			System.out.println(a + "-" + b + "-" + c + "-" + d + "=7");
			return;
		}
	}
}