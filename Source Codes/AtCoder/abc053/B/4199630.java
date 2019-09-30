import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		int startA = 0;
		int endZ = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'A') {
				startA = i;
				break;
			}
		}
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.charAt(i) == 'Z') {
				endZ = i;
				break;
			}
		}
		System.out.println(endZ - startA + 1);
		sc.close();
	}
}