import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int n=scan.nextInt();
		int k=scan.nextInt();

		long INF = 1000000007;
		long ans=1;
		for(int i=k+1;i<n+k;i++){
			ans*=i;
			ans%=INF;
		}


		long div[] = new long[31];
		div[0]=1;
		for(int i=1;i<n;i++){
			div[0]*=i;
			div[0]%=INF;
		}
		//div[0]=(n-1)! % INF

		int[] two =new int[31];
		two[0]=1;
		for(int i=1;i<31;i++){
			two[i]=two[i-1]*2;
			div[i]=div[i-1]*div[i-1];
			div[i]%=INF;
		}
		//two[i] = 2^i
		//div[i]=(n-1)!^i % INF


		long mom=1;
		for(int i=0;i<31;i++){
		//	System.out.println(two[i]^(INF-2));
			if((two[i]&(INF-2))>0){
				mom*=div[i];
				mom%=INF;
			}
		}
		ans*=mom;
		ans%=INF;


		System.out.println(ans);
	}

}
// a*b % INF = (a%INF * b%INF)%INF
//??? a/b = a * b^(-1)
//(a%INF * b^-1%INF)%INF
//b^-1 = b^(INF-2) (mod INF)