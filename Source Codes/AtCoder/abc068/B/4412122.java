import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int ans = 1;
		int max = 0;
		for (int i = 2; i <= n; i++) {
			int tmp = i;
			int tmpCount = 0;
			while (tmp % 2 == 0) {
				tmp /= 2;
				tmpCount++;
			}
			if(max < tmpCount){
				max = tmpCount;
				ans = i;
			}
		}
		System.out.println(ans);
	}
}