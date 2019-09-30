import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] p=new int[44];
		long[] a1=new long[n];
		for(int i = 0; i<n; i++){
			long a= sc.nextLong();
			a1[i]=a;
			int count=0;
			while(a>0){
				if((a & 1)==1){
					p[count]++;
				}
				a>>=1;
				count++;
			}
		}
		long[] pow=new long[44];
		pow[0]=1;
		for(int i = 1; i<44; i++){
			pow[i]=pow[i-1]*2;
		}
		long ans=0;
		for(int i = 43; i>=0; i--){
			if(p[i]*2<=n){
				if(ans+pow[i]<=k){
					ans+=pow[i];
				}
			}
		}
		long an=0;
		for(int i = 0; i<n; i++){
			an+=ans^a1[i];
		}
		System.out.println(an);
	}
}