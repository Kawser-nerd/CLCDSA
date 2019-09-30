import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		boolean[] a = new boolean[26];
		for (int i = 0; i < s.length(); i++) {
			a[s.charAt(i) - 'a'] = true;
		}
		for (int i = 0; i < a.length; i++) {
			if (!a[i]) {
				System.out.println(Character.toChars(i + 'a'));
				return;
			}
		}
		System.out.println("None");
	}
}