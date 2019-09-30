import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int two,three,four;
		if(m % 2 == 0) {
			three = 0;
			two = (4 * n - m) / 2;
			four = n - two;
		}else {
			three = 1;
			two = (4 * n - m - 1) / 2;
			four = n - 1 - two;
		}

		if(two < 0 || four < 0) {
			System.out.println("-1 -1 -1");
		}else {
			System.out.println(two + " " + three + " " + four);
		}

	}
}