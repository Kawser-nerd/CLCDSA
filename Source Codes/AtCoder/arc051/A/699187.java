import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int x1 = in.nextInt();
		int y1 = in.nextInt();
		int r = in.nextInt();
		int x2 = in.nextInt();
		int y2 = in.nextInt();
		int x3 = in.nextInt();
		int y3 = in.nextInt();
		if (x1 - r >= x2 && x1 + r <= x3 && y1 - r >= y2 && y1 + r <= y3){
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
		if (dis(x1,y1,x2,y2) <= r && dis(x1,y1,x3,y2) <= r && dis(x1,y1,x2,y3) <= r && dis(x1,y1,x3,y3) <= r){
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
	
	public static double dis(int x1,int y1,int x2,int y2){
		return Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	}

}