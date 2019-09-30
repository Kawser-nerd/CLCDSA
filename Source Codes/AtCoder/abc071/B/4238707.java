import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		boolean[] b = new boolean[26];
		for (int i = 0; i < s.length(); i++) {
			b[s.charAt(i) - 'a'] = true;
		}

		String ans = "None";
		for (int i = 0; i < b.length; i++) {
			if (!b[i]) {
				ans = "" + (char)('a' + i);
				break;
			}
		}

		System.out.println(ans);

		sc.close();
	}
}