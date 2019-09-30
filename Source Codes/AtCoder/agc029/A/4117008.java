import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		long sum = 0;
		long count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'W') {
				count++;
				sum += i;
			}
		}
		System.out.println(sum - count * (count - 1) / 2);
	}
}