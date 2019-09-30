import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		boolean flag = false;
		int total = 0;
		int sum = 0;
		for (char c : arr) {
			if (flag) {
				total += 9;
			} else {
				if (c == '9') {
					total += 9;
				} else {
					if (total == 0) {
						total += c - '0' - 1;
						flag = true;
					} else {
						total--;
						total += 9;
						flag = true;
					}
				}
			}
			sum += c - '0';
		}
		System.out.println(Math.max(total, sum));
	}
}