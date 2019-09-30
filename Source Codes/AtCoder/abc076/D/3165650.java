import java.util.*;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] t=new int[n];
		int[] v=new int[n+1];
		Arrays.setAll(t,i->s.nextInt());
		for(int i=0;i<n;++i)
			v[i]=s.nextInt();
		for(int i=n-1;i>=0;--i)
			v[i]=Math.min(v[i],v[i+1]+t[i]);

		Arrays.parallelPrefix(t,Integer::sum);

		int cv=0,i=0,d=0;
		for(int T=0;T<t[n-1];++T){
			int remain=t[i]-T;
			if(cv-v[i+1]==remain-1&&cv<v[i]){
				d+=cv*4+1;
			}else{
				d+=cv*2;
				if(cv-v[i+1]==remain)
					cv--;
				else if(cv+1<=v[i])
					cv++;
				d+=cv*2;
			}
			if(remain==1)
				++i;
		}
		System.out.println(d/4.0);
	}
}