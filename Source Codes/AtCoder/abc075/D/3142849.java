import java.util.*;

class Main{
	static Scanner s=new Scanner(System.in);
	public static void main(String[] $){
		int n=s.nextInt(),k=s.nextInt();
		int[]x=new int[n],y=new int[n];
		for(int i=0;i<n;++i) {
			x[i]=s.nextInt();
			y[i]=s.nextInt();
		}
		long res=Long.MAX_VALUE;
		for(int i=0;i<n;++i) {
			for(int j=i+1;j<n;++j) {
				long l=Math.min(x[i],x[j]);
				long r=Math.max(x[i],x[j]);
				
				for(int p=0;p<n;++p) {
					for(int q=p+1;q<n;++q) {
						long t=Math.min(y[p],y[q]);
						long b=Math.max(y[p],y[q]);
						
						int c=0;
						for(int o=0;o<n;++o) {
							if(l<=x[o]&&x[o]<=r&&t<=y[o]&&y[o]<=b){
								++c;
							}
						}
						if(c>=k)
							res=Math.min(res,(r-l)*(b-t));
					}
				}
			}
		}
		System.out.println(res);
	}
}