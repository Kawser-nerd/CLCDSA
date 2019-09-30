import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a, b, c;
		int d;
		a = sc.next();
		b = sc.next();
		c = a.concat(b);
		d = Integer.parseInt(c);
		for (int i = 0; i < d / 2; i++) {
			if (i * i == d) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
		sc.close();
	}

}