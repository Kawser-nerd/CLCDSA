import java.awt.Point;
import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[]$){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		Point[]p=new Point[n];
		Arrays.setAll(p,o->new Point(s.nextInt(),s.nextInt()));

		int r=0;
		for(int i=0;i<n;++i) {
			Point a=p[i];
			for(int j=i+1;j<n;++j) {
				Point b=p[j];
				for(int k=j+1;k<n;++k){
					Point c=p[k];
					if(Math.atan2(a.y-b.y,a.x-b.x)!=Math.atan2(a.y-c.y,a.x-c.x)&&(f(a,b)+f(b,c)+f(c,a))%2==0)
						++r;
				}
			}
		}
		System.out.println(r);
	}
	static long f(Point a,Point b){
		return Math.abs((long)(a.x-b.x)*(a.y-b.y));
	}
}