import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		long n = Long.parseLong(s);
		String[] t = s.split("");
		if (n == 3 || n == 2 || n == 5) {
			System.out.println("Prime");
			return;
		}
		if (n % 2 == 0 || n % 5 == 0 || n == 1) {
			System.out.println("Not Prime");
			return;
		}
		long sum = 0;
		for (int i = 0; i < t.length; i++)
			sum += Integer.parseInt(t[i]);
		if (sum % 3 == 0)
			System.out.println("Not Prime");
		else
			System.out.println("Prime");
	}
}