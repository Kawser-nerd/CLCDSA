import java.util.*;

public class Main {
	static final String[] CHOKU = new String[]{"ch", "o", "k", "u"};
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		while (s.length() > 0) {
			boolean flag = false;
			for (String end : CHOKU) {
				if (s.endsWith(end)) {
					flag = true;
					s = s.substring(0, s.length() - end.length());
					break;
				}
			}
			if (!flag) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}