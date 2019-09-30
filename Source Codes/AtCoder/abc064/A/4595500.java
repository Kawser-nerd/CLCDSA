import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int r = reader.nextInt();
		int g = reader.nextInt();
		int b = reader.nextInt();
		int num = r * 100 + g * 10 + b;
		String ans = "NO";
		if (num % 4 == 0) {
			ans = "YES";
		}
		reader.close();
		System.out.print(ans);
	}
}