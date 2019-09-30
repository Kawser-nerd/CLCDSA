import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0; i<N; i++)
			A[i] = sc.nextInt();
		
		System.out.println(win(A) ? "First" : "Second");
		
		sc.close();
	}
	
	static boolean win(int[] A) {
		int N = A.length;
		int even = 0;
		for(int i=0; i<N; i++)
			if(A[i]%2==0)
				even++;
		if(even%2==1) {
			return true;
		} else {
			if(even==N-1) {
				for(int i=0; i<N; i++) {
					if(A[i]%2==1) {
						if(A[i]==1)
							return false;
						A[i]--;
						break;
					}
				}
				int gcd = A[0];
				for(int i=1; i<N; i++)
					gcd = gcd(gcd, A[i]);
				for(int i=0; i<N; i++)
					A[i] /= gcd;
				return !win(A);
				
			} else {
				return false;
			}
		}
	}
	
	static int gcd(int a, int b) {
		return a%b==0 ? b : gcd(b, a%b);
	}
}