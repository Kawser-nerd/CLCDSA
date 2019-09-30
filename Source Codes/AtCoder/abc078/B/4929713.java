import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int X = sc.nextInt();

		int Y = sc.nextInt();

		int Z = sc.nextInt();

		int ans = 0;

		X -= Z;

		ans = X/(Y+Z);

		System.out.println(ans);

	}
}