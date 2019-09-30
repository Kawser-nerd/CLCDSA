import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong(),k=sc.nextLong();
		long[] divs=divs(n);
		int nd=divs.length;
		long mod=1000000007;
		
		HashMap<Long,Long> map=new HashMap<>();
		long res=0;
		for(int i=0;i<nd;i++){
			long div=divs[i];
			long[] dd=divs(div);
			
			long nama=modPow(k,(div+1)/2,mod);
			for(int j=0;j<dd.length-1;j++){
				nama=(nama-map.get(dd[j])+mod)%mod;
			}
			map.put(div,nama);
			long coef=(div%2==1?div:div/2);
			res=(res+nama*coef%mod)%mod;
			//System.out.println(div+" "+res);
		}
		System.out.println(res);
	}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1) res=res*c%mod;
			c=c*c%mod;
			b/=2;
		}
		return res;
	}
	static long[] divs(long x){
		long[] res=new long[(int)(Math.sqrt(x)+2)*2];
		int size=0;
		long i=1;
		for(;i*i<x;i++){
			if(x%i>0)continue;
			res[size++]=i;
		}
		if(i*i==x) res[size++]=i;
		i--;
		for(;i>0;i--){
			if(x%i>0)continue;
			res[size++]=x/i;
		}
		return Arrays.copyOf(res,size);
	}
}