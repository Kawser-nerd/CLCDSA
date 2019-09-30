import java.awt.Point;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	private void solve() {
		Scanner in = new Scanner(System.in);
		int x1 = in.nextInt();
		int y1 = in.nextInt();
		int x2 = in.nextInt();
		int y2 = in.nextInt();
		
		if(y2<y1){
			int sp = y2;
			y2 = y1;
			y1 =sp;
			sp = x2;
			x2 = x1;
			x1 = sp;
		} // y1 < y2
		
		int N = in.nextInt();
		
		if(x1==x2){
			boolean exist = false;
			for (int i = 0; i < N; i++) {
				int x = in.nextInt();
				int y = in.nextInt();
				if(x==x1 && y1<y && y<y2) exist = true;
			}
			System.out.println(100L*(y2-y1)+((!exist)?0:10*Math.PI-20));
			
		}else if(y1==y2){
			boolean exist = false;
			if(x1>x2){
				int sp = x2; x2 = x1; x1 = sp;
			}
			for (int i = 0; i < N; i++) {
				int x = in.nextInt();
				int y = in.nextInt();
				if(y==y1 && x1<x && x<x2) exist = true;
			}
			System.out.println(100L*(x2-x1)+((!exist)?0:10*Math.PI-20));
			
		}else{
			LinkedList<Point> queue = new LinkedList<>();
			for (int i = 0; i < N; i++) {
				queue.offer(new Point(in.nextInt(),in.nextInt()));
			}
			Collections.sort(queue,
					(x1<x2)?
					(a,b)->((Point)a).x-((Point)b).x :
					(a,b)->((Point)b).x-((Point)a).x
			);
			
			BinaryPoints tree = new BinaryPoints();
			while(!queue.isEmpty()){
				Point p = queue.poll(); 
				if(between(p.x,x1,x2) && between(p.y,y1,y2))
					tree.add(p.y);
			}
			int max = tree.lis();
			double ans = 100L*(Math.abs(x2-x1)+(y2-y1));
			if(max==Math.min(Math.abs(x2-x1), y2-y1)+1){
				ans += (5*Math.PI-20)*(max-1) + 10*Math.PI-20;
			}else{
				ans += (5*Math.PI-20)*max;
			}
			System.out.println(ans);
			
		}
	}
	
	private boolean between(int target, int edge1, int edge2){
		return Math.min(edge1,edge2)<=target 
				&& target<= Math.max(edge1, edge2);
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}


class BinaryPoints{
	ArrayList<Integer> dp;
	
	public BinaryPoints(){
		dp = new ArrayList<Integer>();
	}
	
	public void add(int y){
		int index = lowerBound(y,0,dp.size());
		if(index>=dp.size()){
			dp.add(y);
		}else{
			dp.set(index, y);
		}
	}
	
	public int lis(){
		return dp.size();
	}
	
	public int lowerBound(int y, int left, int right){// [left,right)
		if(right==left) return right;
		int index = (left+right)/2;
		if(dp.get(index)>=y){
			return lowerBound(y,left,index);
		}else{
			return lowerBound(y,index+1,right);
		}
	}
}