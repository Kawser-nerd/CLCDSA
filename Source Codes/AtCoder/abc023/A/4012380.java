import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		int ans = 0;
		for (char c : s.toCharArray()) {
			ans += Integer.parseInt(""+c);
		}
		
		System.out.println(ans);
	}
}