import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] a=new long[n],b=new long[n];
		long res=0;
		boolean same=true;
		for(int i=0;i<n;i++){
			a[i]=sc.nextLong();
			b[i]=sc.nextLong();
			if(a[i]!=b[i]) same=false;
		}
		if(same){
			System.out.println(0);
			return;
		}
		long min=Long.MAX_VALUE;
		for(int i=0;i<n;i++){
			if(a[i]<=b[i]){
				res+=a[i];
				b[i]-=a[i];
				a[i]=0;
				res+=b[i];
			}else{
				min=Math.min(min,b[i]);
				res+=b[i];
			}
		}
		System.out.println(res-min);
	}
}