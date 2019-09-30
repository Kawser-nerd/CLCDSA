import java.util.*;

public class Main {
	public static void main(String[] args) {
		//ABC086A(); 
		//ABC081A();
		TravelingPlan();
	}

	public static void ABC086A() {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		if((a * b) % 2 == 0) {
			System.out.println("Even");
		}else {
			System.out.println("Odd");
		}
	}
	
	public static void ABC081A() {
		Scanner scan = new Scanner(System.in);
		String str = scan.next();
		char chr[] = str.toCharArray();
		int count = 0;
		for(int i = 0; i < 3; i++) {
			if(chr[i] == '1')
				count++;
		}
		System.out.println(count);
	}
	
	public static void TravelingPlan() {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int[] A = new int[N + 2];
		for(int i = 1; i < N + 1; i++) {
			A[i] = scan.nextInt();
		}
		A[0] = 0;
		A[N + 1] = 0;
		int ans = 0;
		
		for(int i = 1; i < N + 2; i++) {
			ans += Math.abs(A[i] - A[i - 1]);
		}

		for(int i = 1; i < N + 1; i++) {
			System.out.println(ans - Math.abs(A[i] - A[i - 1]) - Math.abs(A[i + 1] - A[i]) + Math.abs(A[i + 1] - A[i - 1]));
		}

	/*	
		for(int a = 0; a < N; a++) {
			int ans = 0;
			int pos = 0;
			for(int i = 0; i < N; i++) {
				if(i == a)
					continue;
				ans += Math.abs(A[i] - pos);
				pos = A[i];
			}
			if(a == N-1)
				ans += Math.abs(A[N-2]);
			else
				ans += Math.abs(A[N-1]);
			System.out.println(ans);
		}
		for(int i = 0; i < N; i++) {
			System.out.println(ans - A[i]);
		}
	*/
	}
}