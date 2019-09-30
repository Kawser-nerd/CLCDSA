import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int m =sc.nextInt();
		Point[] p= new Point[m];
		int ans=1;
		for(int i = 0; i<m; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			p[i]=new Point(a,b);
		}
		Arrays.sort(p, Comparator.comparing(Point::getY));
		Arrays.sort(p, Comparator.comparing(Point::getX));
		for(int i = 0; i<m; i++){
			int last=p[i].y;
			for(int j=i+1; j<m; j++){
				if(p[j].x>=last){
					i=j-1;
					ans++;
					break;
				}else{
					last=Math.min(last,p[j].y);
				}
			}
		}
		System.out.println(ans);
	}
	static class Point{
		int x;
		int y;
		public Point(int x, int y){
			this.x=x;
			this.y=y;
		}
		
		public int getX(){
			return x;
		}
		 
		public int getY(){
			return y;
		}
	}
}