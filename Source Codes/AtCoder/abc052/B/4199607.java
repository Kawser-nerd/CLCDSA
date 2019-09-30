import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		sc.next();
		String s = sc.next();

		int max = 0;
		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'I') {
				sum++;
			} else {
				sum--;
			}
			if (max < sum) {
				max = sum;
			}
		}
		System.out.println(max);

		sc.close();
	}
}