import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		int minSub = 1000;
		for (int i = 0; i + 2 < s.length(); i++) {
			int x = Integer.parseInt(s.substring(i, i + 3));
			int sub = 753 - x;
			if (sub < 0)
				sub *= -1;
			if (sub < minSub) {
				minSub = sub;
			}
		}
		System.out.println(minSub);
		sc.close();
	}
}