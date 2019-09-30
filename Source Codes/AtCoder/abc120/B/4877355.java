import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		int A=sc.nextInt();
		int B=sc.nextInt();
		int K=sc.nextInt();

		System.out.println(Divisor(A,B,K));

		sc.close();

	}

	public static int Divisor(int a,int b,int k) {

		int ans=0;

		for(int i=100;i>0;i--) {
			if(a%i==0 && b%i==0) {

				//System.out.println(i+" "+k);

				k--;
				ans=i;
				if(k==0) break;
			}
		}

		return ans;

	}

}