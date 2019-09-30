import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int next = 11;
		String ans = "";
		while (N > 0 && next <= 55555) {
			if (isPrime(next)) {
				ans += next + " ";
				N--;
			}
			next += 10;
		}


		System.out.print(ans.substring(0, ans.length()-1));
		reader.close();
	}
	public static boolean isPrime(int num) {
		boolean result = true;
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				result = false;
			}
		}
		return result;
	}
}