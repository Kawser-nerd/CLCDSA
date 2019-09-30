import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int min = Integer.MAX_VALUE;
		for (char c = 'a'; c <= 'z'; c = (char)(c + 1)) {
			int max = 0;
			int current = 0;
			String t = String.valueOf(c);
			int idx = s.indexOf(t);
			while (idx != -1) {
				if (max < idx - current) {
					max = idx - current;
				}
				current = idx + 1;
				idx = s.indexOf(t, current);
			}
			if (max < s.length() - current + 1) {
				max = s.length() - current;
			}
			if (min > max) {
				min = max;
			}
		}
		System.out.println(min);
	}
}