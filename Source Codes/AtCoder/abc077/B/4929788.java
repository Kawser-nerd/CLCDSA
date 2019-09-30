import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		double sq = Math.sqrt(N);

		int ans = (int)sq * (int) sq;

		System.out.println(ans);

	}
}