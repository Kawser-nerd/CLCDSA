import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextInt();
		long B = sc.nextInt();
		long C = sc.nextInt();
		long K = sc.nextLong();
		if(C == 0)
		sc.close();
		long ans = B - A;
		if(K % 2 == 0) {
			ans *= -1;
		}
		System.out.println(ans);
	}
}