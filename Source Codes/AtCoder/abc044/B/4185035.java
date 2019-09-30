import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		while (!s.equals("")) {
			Character c = s.charAt(0);
			int count = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == c.charValue()) {
					count++;
				}
			}
			if (count % 2 == 1) {
				System.out.println("No");
				sc.close();
				return;
			}
			s = s.replaceAll(c.toString(), "");
		}

		System.out.println("Yes");
		sc.close();
	}
}