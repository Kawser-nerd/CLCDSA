import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);

		long A=sc.nextLong();
		long B=sc.nextLong();
		long K=sc.nextLong();
		long L=sc.nextLong();

		if(B==A*L) {
			System.out.println(A*K);
		}
		else {
			System.out.println(Math.min((B*((K+L-1)/L)), B*(K/L)+A*((K-(K/L)*L))));
		}
	}
}