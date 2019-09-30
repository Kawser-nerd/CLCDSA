import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long xor=0;
		for(int i=0;i<n;i++){
			int a=sc.nextInt();
			int k=sc.nextInt();
			xor^=grundy(a,k);
		}
		System.out.println((xor==0)?"Aoki":"Takahashi");
	}
	static long grundy(int a,int k){
		if(a%k==0)return a/k;
		if(a<k)return 0;
		long d=a/k+1;
		long rem=a%d;
		long c=(long)Math.ceil((double)(a/k*k-rem)/d);
		long b=d*c+rem;
		if(b%k==0)return b/k;
		a=(int)(b-d);
		return grundy(a,k);
	}
}