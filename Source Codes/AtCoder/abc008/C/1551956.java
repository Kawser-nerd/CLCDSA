import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] C = new long[N];
		for(int i=0; i<N; i++) {
			C[i] = sc.nextLong();
		}
		sc.close();
		double ans=0;
		for(int i=0; i<N; i++) {
			int S=0;
			for(int j=0; j<N; j++) {
				if(j!=i && C[i] % C[j] == 0) {
					S++;
				}
			}
			if(S%2==0) {
				ans += (double)(S+2)/(double)(2*S+2);
			} else {
				ans += (double)(1)/(double)(2);
			}
		}
		System.out.println(ans);
	}

}