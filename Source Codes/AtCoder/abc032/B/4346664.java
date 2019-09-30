import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int k = sc.nextInt();
		Set<String> set = new TreeSet<>();
		for (int i = 0; i + k <= s.length(); i++) {
			set.add(s.substring(i, i + k));
		}
		System.out.println(set.size());
	}
}