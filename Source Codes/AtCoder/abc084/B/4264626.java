import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		String s = sc.next();

		String ans = "Yes";
		for (int i = 0; i < s.length(); i++) {
			if (i == a) {
				if (s.charAt(i) != '-') {
					ans = "No";
					break;
				}
			} else {
				if (s.charAt(i) == '-') {
					ans = "No";
					break;
				}
			}
		}
		System.out.println(ans);
		sc.close();
	}

}