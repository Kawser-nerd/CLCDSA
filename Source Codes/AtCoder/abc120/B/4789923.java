import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		int min = Math.min(A,B);
		int j = 0;
		for (int i = min; i > 0; i--) {
			if (A % i == 0  && B % i == 0) j += 1;
			if ( j == K) {
			System.out.println(i);
			break;
			}
		}
	}

}