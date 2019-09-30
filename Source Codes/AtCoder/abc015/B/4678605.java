import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		int n=sc.nextInt();
		double ans=0;int zero=0;
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			if(a==0)zero++;
			ans+=a;
		}
		System.out.println(Math.ceil(ans/(n-zero)));
	}
}