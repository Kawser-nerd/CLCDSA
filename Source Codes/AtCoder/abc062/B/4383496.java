import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int h = sc.nextInt(), w = sc.nextInt();
		String[] s = new String[h];
		for (int i = 0; i < h; i++) {
			s[i] = sc.next();
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < w + 2; i++) {
			sb.append("#");
		}
		System.out.println(sb);
		for (int i = 0; i < h; i++) {
			System.out.println("#" + s[i] + "#");
		}
		System.out.println(sb);
	}
}