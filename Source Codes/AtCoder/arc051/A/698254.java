import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		int r = sc.nextInt();
		int x2 = sc.nextInt();
		int y2 = sc.nextInt();
		int x3 = sc.nextInt();
		int y3 = sc.nextInt();
		
		System.out.println(x2<=x1-r && x1+r<=x3 && y2<=y1-r && y1+r<=y3 ? "NO" : "YES");
		System.out.println(inside(x1,y1,r,x2,y2) && inside(x1,y1,r,x2,y3) && inside(x1,y1,r,x3,y2) && inside(x1,y1,r,x3,y3) ? "NO" : "YES");
		sc.close();
	}
	
	static boolean inside(int x0, int y0, int r, int x1, int y1) {
		return (x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)<=r*r;
	}
}