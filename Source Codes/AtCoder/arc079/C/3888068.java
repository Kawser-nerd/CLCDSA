import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] a=new long[n];
		for(int i=0;i<n;i++) a[i]=sc.nextLong();
		long sum=0;
		for(long lo:a) sum+=lo;
		long res=0;
		while(true){
			long[] b=new long[n];
			for(int i=0;i<n;i++){
				long sho=a[i]/n;
				a[i]%=n;
				for(int j=0;j<n;j++){
					if(i==j) continue;
					b[j]+=sho;
				}
			}
			for(int i=0;i<n;i++) a[i]+=b[i];
			boolean allzero=true;
			for(long lo:b) if(lo!=0)allzero=false;
			if(allzero)break;
		}
		for(long lo:a)sum-=lo;
		System.out.println(sum);
	}
}