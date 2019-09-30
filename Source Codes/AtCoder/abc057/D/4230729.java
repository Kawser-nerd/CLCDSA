import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		long[] t=new long[n];
		long r=0;
		long p1=0;
		long p2=0;
		for(int i = 0; i<n; i++){
			long v = sc.nextLong();
			t[i]=v;
			
		}
		Arrays.sort(t);
		double ans1=0;
		long ans2=0;
		for(int i=0; i<n; i++){
			if(i<=a-1){
				ans1+=t[n-1-i];
			}
			if(r==t[n-1-i]){
				p1++;
			}else{
				if(i<=a-1){
					r=t[n-1-i];
					p1=1;
				}else{
					break;
				}
			}
			if(i==a-1){
				p2=p1;
			}
		}
		if(p2!=a){
			if(((ans1-r*p2)/(a-p2))==r){
				for(long i = p2; i<=Math.min(b-a+p2,p1); i++){
					ans2+=c(p1,i);
				}
			}else{
				ans2+=c(p1,p2);
			}
		}else{
			for(long i = p2; i<=Math.min(b-a+p2,p1); i++){
				ans2+=c(p1,i);
			}
		}
		System.out.println(ans1/a);
		System.out.println(ans2);
	}
	public static long c(long o,long l){
		long ans=1;
		for(long i = 1; i<=l; i++){
			ans*=o-i+1;
			ans/=i;
		}
		return ans;
	}
}