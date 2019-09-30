import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int s=sc.nextInt();
		long mod=1000000007;
		
		long res=0;
		int[] divs=divs(s);
		for(int i:divs){
			int kosu=s/i;
			if(i<8) continue;
			res=(res+modPow(10,i-1,mod)*9%mod-kosu)%mod;
		}
		
		int[] sum=new int[30000000];
		long are=1;
		int keta=1;
		for(int i=1;i<sum.length;i++){
			if(i==are*10){
				are=i;
				keta++;
			}
			sum[i]=sum[i-1]+keta;
		}
		int right=1;
		for(int left=1;left<10000000;left++){
			while((sum[right]-sum[left-1])<s)right++;
			if((sum[right]-sum[left-1])==s)res++;
		}
		
		res+=s/8;
		System.out.println(res%mod);
	}
	static int[] divs(int x){
		int[] res=new int[100000];
		int size=0;
		for(int i=1;i*i<=x;i++){
			if(x%i==0) res[size++]=i;
		}
		for(int i=size-1;i>=0;i--){
			if(res[i]*res[i]==x)continue;
			res[size++]=x/res[i];
		}
		res=Arrays.copyOf(res,size);
		return res;
	}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1) res=(res*c)%mod;
			c=(c*c)%mod;
			b/=2;
		}
		return res;
	}
}