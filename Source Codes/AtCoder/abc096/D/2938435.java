import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[] ans = new int[N];
		ans[0] = 2;
		int ansPtr = 1;
		
		int[] prime = new int[1000];
		prime[0] = 2;
		int ptr = 1;
		int num = 3;
		while(ansPtr<N) {
			boolean isPrime = true;
			for(int i=1;i<ptr && prime[i]*prime[i]<=num;i++) {
				if(num%prime[i]==0) {
					isPrime = false;
					break;
				}
			}
			if(isPrime) {
				prime[ptr++] = num;
				if(num%5==1) {
					ans[ansPtr++] = num;
				}
			}
			num += 2;
		}
		
		for(int i=0;i<N;i++) {
			System.out.print(ans[i]+" ");
		}
		
		in.close();

	}

}