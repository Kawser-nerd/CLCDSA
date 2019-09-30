import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		judge(sc.nextInt(), sc.nextInt());

		sc.close();
	}

	static void judge(int n, int m) {
		int a = n == 1 ? 14 : n;
		int b = m == 1 ? 14 : m;

		System.out.println(a > b ? "Alice" : a == b ? "Draw" : "Bob");

	}
}