import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String ans = "Yes";
		String wo[] = new String[n];
		for (int i = 0; i < n; i++) {
			wo[i] = sc.next();

			for (int j = 0; j < i; j++) {
				if (wo[j].equals(wo[i])) {
					ans = "No";
				}
			}
		}
		for (int i = 1; i < n; i++) {
			if (wo[i - 1].charAt(wo[i - 1].length() - 1) != wo[i].charAt(0)) {
				ans = "No";
			}
		}
		System.out.println(ans);

	}
}