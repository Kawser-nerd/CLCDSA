import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		int t = sc.nextInt();
		Point[] p=new Point[n];
		for(int i = 0; i<n; i++){
			long x = sc.nextLong();
			long y = sc.nextLong();
			p[i]=new Point(x,y);
		}
		long ans=Long.MAX_VALUE;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				for(int k = 0; k<n; k++){
					for(int l = 0; l<n; l++){
						int count=0;
						for(int u=0; u<n; u++){
							if(p[u].x<=p[i].x && p[u].x>=p[j].x && p[u].y<=p[k].y && p[u].y>=p[l].y){
								count++;
							}
						}
						if(count>=t){
							ans=Math.min(ans,(p[i].x-p[j].x)*(p[k].y-p[l].y));
						}
					}
				}
			}
		}
		System.out.println(ans);
	}
	static class Point{
		long x;
		long y;
		public Point(long x,long y){
			this.x=x;
			this.y=y;
		}
	}
}