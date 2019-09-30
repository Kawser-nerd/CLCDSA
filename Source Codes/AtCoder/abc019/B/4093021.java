import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		StringBuilder sb = new StringBuilder();
		char prev = '1';
		int count = 1;
		for (char c : arr) {
			if (prev == '1') {
				prev = c;
			} else if (prev == c) {
				count++;
			} else {
				sb.append(prev).append(count);
              prev = c;
              count = 1;
			}
		}
		sb.append(prev).append(count);
		System.out.println(sb);
	}
}