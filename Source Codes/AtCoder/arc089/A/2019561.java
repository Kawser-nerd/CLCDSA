import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Main m = new Main();
		m.run();
	}
	
	Scanner sc = new Scanner(System.in);
	
	void run(){
		int N = sc.nextInt();
		
		int prevT = 0;
		int prevX = 0;
		int prevY = 0;
		boolean mutFlag = true;
		for (int i = 0; i < N ; i++){
			int t = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			mutFlag = check(t,x,y,prevT,prevX,prevY);
			if(!mutFlag){
				break;
			}
			prevT = t;
			prevX = x;
			prevY = y;
		}
		System.out.println(mutFlag ?"Yes" :"No");
		
		
	}
	
	boolean check(int t1,int x1,int y1, int t0,int x0,int y0){
		int time = t1 - t0;
		
		int distance = Math.abs(x1 - x0) + Math.abs(y1 - y0);
		if((distance + time) % 2 == 1){
			return false;
		}
		return distance <= time;
	}
}