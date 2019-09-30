import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		for (int i = (s.length() - 1) / 2; i > 0; i--) {
			if (s.substring(0, i).equals(s.substring(i, i * 2))) {
				System.out.println(i * 2);
				return;
			}
		}
	}
}