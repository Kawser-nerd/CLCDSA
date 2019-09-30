import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		int ans = 0;
		while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
			int tempA = B / 2 + C / 2;
			int tempB = A / 2 + C / 2;
			int tempC = A / 2 + B / 2;
			if(A == tempA && B == tempB && C == tempC) {
				System.out.println(-1);
				return;
			}
			ans++;
			A = tempA;
			B = tempB;
			C = tempC;
		}
		
		System.out.println(ans);
	}
}