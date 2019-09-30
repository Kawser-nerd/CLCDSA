import java.util.Scanner;
import java.awt.Point;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h= sc.nextInt();
		int w = sc.nextInt();
		int d=sc.nextInt();
		Point[] ar=new Point[h*w+1];
		int[] ans=new int[h*w];
		for(int i = 1; i<=h; i++){
			for(int j = 1; j<=w; j++){
				ar[sc.nextInt()]=new Point(i,j);
			}
		}
		for(int i = 1; i<h*w+1; i++){
			if(i<=d){
				ans[i-1]=0;
			}else{
				ans[i-1]+=ans[i-1-d]+Math.abs(ar[i].x-ar[i-d].x)+Math.abs(ar[i].y-ar[i-d].y);
			}
		}
		int q=sc.nextInt();
		int[] ans1=new int[q];
		for(int i = 0; i<q; i++){
			int l=sc.nextInt();
			int r=sc.nextInt();
			ans1[i]=ans[r-1]-ans[l-1];
		}
		for(int i = 0; i<q; i++){
			System.out.println(ans1[i]);
		}
	}
}