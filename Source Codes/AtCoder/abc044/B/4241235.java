import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String w = sc.next();
		int[] count = new int[26];
		for (int i = 0; i < w.length(); i++) {
			count[w.charAt(i) - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (count[i] % 2 != 0) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}
}