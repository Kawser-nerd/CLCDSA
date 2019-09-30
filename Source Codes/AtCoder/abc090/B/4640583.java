import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int sum = 0;
		for (int i = a; i <= b; i++) {
			int c = 1;
			String s = String.valueOf(i);
			for (int j = 0; j < 5 / 2; j++) {
				if (s.charAt(j) != s.charAt(5 - j - 1)) {
					c = 0;
				}
			}
			if (c != 0) {
				sum++;
			}
		}
		System.out.println(sum);
		sc.close();
	}

}