import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Point[] p = new Point[n];
		int ans=0;
		for(int i = 0; i<n; i++){
			int w = sc.nextInt();
			int h = sc.nextInt();
			p[i]=new Point(w,h);
		}
		Arrays.sort(p,new Comparator<Point>(){
			public int compare(Point p1,Point p2){
				if(p1.x==p2.x){
					return -(p1.y-p2.y);
				}else{
					return p1.x-p2.x;
				}
			}	
		});
		
		int[] max=new int[n+1];
		Arrays.fill(max,Integer.MAX_VALUE);
		max[0]=0;
		for(int i = 0; i<n; i++){
			int idx=Arrays.binarySearch(max,p[i].y);
			if(idx<0){
				idx=-idx-1;
				max[idx]=Math.min(max[idx],p[i].y);
			}
		}
		for(int i=n; i>=0; i--){
			if(max[i]<Integer.MAX_VALUE){
				System.out.println(i);
				return;
			}
		}
	}
	static class Point{
		int x;
		int y;
		public Point(int x, int y){
			this.x=x;
			this.y=y;
		}
	}
}