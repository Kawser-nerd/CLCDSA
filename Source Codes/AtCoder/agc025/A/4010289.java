import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int A = String.valueOf(N).length();
		int B = 10;
		int have = N;
		int sum = 0;
		for(int i = 0;i < (A - 2);i++) {
			B *= 10;
		}
		if(N % B == 0) {
			sum = 10;
			System.out.println(sum);
			System.exit(0);
		}
		sum = N / B;
		for(;;) {
			have = have - (have / B) * B;
			B /= 10;
			if(B == 0) {
				break;
			}
			sum += have / B;
		}
		System.out.println(sum);
	}
}