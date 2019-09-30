import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);

		long NICYOUEN=2000000000000L;

		long A=sc.nextLong();
		long K=sc.nextLong();
		int nisu=0;

		if(K==0) {
			System.out.println(NICYOUEN-A);
		}
		else {
			while(true) {
				A=1+(K+1)*A;
				nisu++;
				if(A>=NICYOUEN) {
					System.out.println(nisu);
					break;
				}
			}
		}
	}
}