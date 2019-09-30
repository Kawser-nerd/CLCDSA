import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String str = sc.next();
		boolean n = false, w = false, s = false, e = false;
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if (c == 'N') {
				n = true;
			} else if (c == 'W') {
				w = true;
			} else if (c == 'S') {
				s = true;
			} else if (c == 'E') {
				e = true;
			}
		}
		if ((n && s || !n && !s) && (w && e || !w && !e)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}