import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int x = sc.nextInt();
		int max = 1;
		for (int i = 2; i <= x; i++) {
			int tmp = i * i;
			while (tmp <= x) {
//				max = Math.max(max, tmp);
				if (tmp > max) {
					max = tmp;
				}
				tmp *= i;
			}
		}
		System.out.println(max);
		sc.close();
	}
}