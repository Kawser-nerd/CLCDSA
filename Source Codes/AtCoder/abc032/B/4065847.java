import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int k = sc.nextInt();
		HashSet<String> set = new HashSet<>();
		for (int i = 0; i + k <= s.length(); i++) {
			String sub = s.substring(i, i + k);
			set.add(sub);
		}
		System.out.println(set.size());
	}
}