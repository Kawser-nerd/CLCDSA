import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long N=sc.nextLong();
		long H=sc.nextLong();
		long A=sc.nextLong();
		long B=sc.nextLong();
		long C=sc.nextLong();
		long D=sc.nextLong();
		long E=sc.nextLong();

		long cost=Long.MAX_VALUE;

		for(long i=0; i<=N; i++) {
			long niti=(-H-i*B+N*E-i*E);
			if(niti<0) {
				niti=0;
			}
			else {
				niti=niti/(D+E)+1;
			}
			cost=Math.min(cost, i*A+niti*C);
		}
		System.out.println(cost);
	}
}