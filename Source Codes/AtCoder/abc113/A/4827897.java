import java.util.Scanner;


public class Main {
	static int N,M;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 N = sc.nextInt();
		 M = sc.nextInt();

		 sc.close();

		 int ans = N+M/2;
		 System.out.println(ans);
	}
}