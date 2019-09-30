import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int i = 1;
		while (i * i <= n) {
			i++;
		}
		i--;

		System.out.println(i * i);

		sc.close();
	}
}