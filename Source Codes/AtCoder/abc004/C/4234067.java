import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String num[] = new String[] {
				"1","2","3","4","5","6"
		};

		N = N%30;

		for (int i = 0; i < N; i++) {
			int r = i%5;
			String tmp;
			tmp = num[r];
			num[r] = num[r+1];
			num[r+1] = tmp;
		}
		String ans = "";
		for (int i = 0; i < num.length; i++) {
			ans += num[i];
		}
		System.out.println(ans);
	}
}