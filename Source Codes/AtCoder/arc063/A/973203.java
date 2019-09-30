import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int ans = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (i == 0 || s.charAt(i) != s.charAt(i - 1))
				++ans;
		}
		--ans;
		System.out.println(ans);
		sc.close();
	}
}