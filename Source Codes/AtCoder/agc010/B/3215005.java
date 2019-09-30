import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		long[]a=new long[n];
		Arrays.setAll(a,i->s.nextInt());
		long sum=Arrays.stream(a).sum();
		if(sum%(n*(n+1L)/2)!=0) {
			System.out.println("NO");
			return;
		}
		long k=sum*2/n/(n+1);
		{
			long t=a[0]-a[n-1];
			for(int i=n-1;i>0;--i)
				a[i]-=a[i-1];
			a[0]=t;
		}
		for(int i=0;i<n;++i)
			a[i]=k-a[i];
		System.out.println(
				Arrays.stream(a).allMatch(i->i>=0&&i%n==0)&&
				Arrays.stream(a).sum()/n==k?"YES":"NO");
	}
}