import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		for (int i = s.length() - 1; i > 0; i--) {
			int l = s.substring(0, i).length();
			if (l % 2 == 1) {
				continue;
			}
			if (s.substring(0, l / 2).equals(s.substring(l / 2, l))) {
				System.out.println(l);
				break;
			}
		}

		sc.close();
	}

}