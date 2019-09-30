import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.println(judge(sc.nextInt(), sc.nextInt(), sc.nextInt()));

		sc.close();
	}

	static String judge(int a, int b, int c) {
		for (int i = 1; i <= b; i++) {
			if (i * a % b == c) {
				return "YES";
			}
		}
		return "NO";
	}

}