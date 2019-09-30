import java.util.Scanner;
import java.util.TreeSet;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		if (s.length() == 26) {
			TreeSet<Character> set = new TreeSet<>();
			set.add(s.charAt(25));
			for (int i = 24; 0 <= i; i--) {
				if (set.higher(s.charAt(i)) != null) {
					System.out.println(s.substring(0, i) + set.higher(s.charAt(i)));
					return;
				} else {
					set.add(s.charAt(i));
				}
			}
			System.out.println(-1);
		} else {
			for (int i = 'a'; i <= 'z'; i++) {
				if (s.indexOf(i) == -1) {
					System.out.println(s + (char)i);
					break;
				}
			}
		}
	}
}