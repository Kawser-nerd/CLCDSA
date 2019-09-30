import java.util.Scanner;

public class Main {

	private static Scanner sc;

	public static void main(String[] args) {

		sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		sb.append(sc.next()).append(sc.next()).append(sc.next());
		int a = Integer.valueOf(sb.toString());
		if (a % 4 == 0) {
			System.out.print("YES");
		} else {
			System.out.print("NO");
		}
	}
}