import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int l = sc.nextInt();
		char[] arr = sc.next().toCharArray();
		int tab = 1;
		int count = 0;
		for (char c : arr) {
			if (c == '+') {
				tab++;
			} else {
				tab--;
			}
			if (tab > l) {
				count++;
				tab = 1;
			}
		}
		System.out.println(count);
	}
}