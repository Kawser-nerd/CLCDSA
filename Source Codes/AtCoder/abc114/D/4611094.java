import java.util.Scanner;
public class Main{
	static int n;
	static long[] s;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		s=new long[n+1];
		long ans=0;
		for(int i=2; i<=n; i++){
			int t=i;
			for(int j=2; j<=t; j++){
				while(t%j==0){
					s[j]++;
					t/=j;
				}
			}
		}
		ans+=count(74);
		ans+=count(24)*(count(2)-1);
		ans+=count(14)*(count(4)-1);
		ans+=count(4)*(count(4)-1)*(count(2)-2)/2;
		System.out.println(ans);
	}
	static long count(int u){
		long res=0;
		for(int i = 2; i<=n; i++){
			if(s[i]>=u){
				res++;
			}
		}
		return res;
	}
}