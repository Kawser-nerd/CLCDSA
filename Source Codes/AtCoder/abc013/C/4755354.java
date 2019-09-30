import java.util.Scanner;
public class Main{
	static int INF=10000;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();long f=sc.nextLong();
		long a1=sc.nextLong();long a2=sc.nextLong();
		long b1=sc.nextLong();long b2=sc.nextLong();
		long c=sc.nextLong();
		long ans=Long.MAX_VALUE;
		for(int i=0;i<=n;i++) {
			long j=0;
			if((n-i)*c-f-a2*i>0)  j=((n-i)*c-f-a2*i)/(b2+c)+1;
			ans=Math.min(ans, a1*i+b1*j);
		}
		System.out.println(ans);
	}
}