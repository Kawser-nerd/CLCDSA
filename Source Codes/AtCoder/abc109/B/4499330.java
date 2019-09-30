import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		String word1 = sc.next();
		String ans = "Yes";
		Set<String> set = new HashSet<>();
		set.add(word1);
		char tale = word1.charAt(word1.length() - 1);

		for (int i = 0; i < n - 1; i++) {
			String str = sc.next();
			if (set.contains(str) || str.charAt(0) != tale) {
				ans = "No";
				break;
			}
			set.add(str);
			tale = str.charAt(str.length() - 1);
		}

		System.out.println(ans);

		sc.close();
	}

}