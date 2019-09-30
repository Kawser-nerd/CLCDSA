import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		int d = scan.nextInt();
		int e = scan.nextInt();

		//?????
		int[] num = new int[5];
		num[0] = a;
		num[1] = b;
		num[2] = c;
		num[3] = d;
		num[4] = e;

		Arrays.sort(num);
		int ans = num[1]+num[2]+num[4];
		int ans2 = num[4]+num[3]+num[0];
		System.out.println(Math.max(ans2, ans));
	}
}