import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int ans=1;
		for(int i=0;i<n;i++) {
			if(ans<m)ans*=2;
			else ans+=m;
		}
		System.out.println(ans);
	}
}