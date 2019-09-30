import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();

		Deque<Point> dq = new ArrayDeque<Point>();
		boolean[] judge = new boolean[k];
		Arrays.fill(judge, true);
		Point now = new Point(1,1);
		dq.add(now);
		while(!dq.isEmpty()){
			Point z = dq.removeFirst();
			if(!judge[(z.x)]){
				continue;
			}
			judge[(z.x)] = false;
			if(z.x == 0){
				System.out.println(z.y);
				break;
			}
			if(judge[(z.x*10)%k]){
				dq.addFirst(new Point((z.x*10)%k, z.y));
			}
			if(judge[(z.x+1)%k]){
				dq.addLast(new Point((z.x+1)%k, z.y+1));
			}
		}
	}
}

class Point{
	int x;
	int y;
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
}