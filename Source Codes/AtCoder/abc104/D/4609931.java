import java.util.Scanner;
public class Main{
	static long mod;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		long[] a=new long[s.length()+1];
		long[] c=new long[s.length()+1];
		long[] q=new long[s.length()+1];
		mod=1000000007;
		for(int i = 1; i<s.length()+1; i++){
			if(s.charAt(i-1)=='A'){
				a[i]++;
			}else if(s.charAt(i-1)=='C'){
				c[i]++;
			}else if(s.charAt(i-1)=='?'){
				q[i]++;
			}
			a[i]+=a[i-1];
			c[i]+=c[i-1];
			q[i]+=q[i-1];
		}
		long ans=0;
		for(int i=1; i<s.length()+1; i++){
			if(s.charAt(i-1)=='B' || s.charAt(i-1)=='?'){
				int bi=0;
				if(s.charAt(i-1)=='?'){
					bi=1;
				}
				ans+=((a[i]*(c[s.length()]-c[i]))%mod)*pow(3,q[s.length()]-bi);
				ans%=mod;
				ans+=((q[i-1]*(c[s.length()]-c[i]))%mod)*pow(3,q[s.length()]-1-bi);
				ans%=mod;
				ans+=((a[i]*(q[s.length()]-q[i]))%mod)*pow(3,q[s.length()]-1-bi);
				ans%=mod;
				ans+=((q[i-1]*(q[s.length()]-q[i]))%mod)*pow(3,q[s.length()]-2-bi);
				ans%=mod;
			}
		}
		System.out.println(ans);
	}
	static long pow(long t,long y){
		long ans=1;
		while(y>0){
			if((y & 1)==1){
				ans*=t;
			}
			ans%=mod;
			t*=t;
			t%=mod;
			y>>=1;
		}
		return ans;
	}
}