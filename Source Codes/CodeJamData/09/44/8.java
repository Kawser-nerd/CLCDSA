import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

class Circle {
	int x,y,r;
	
	public Circle(int x, int y, int r) {
		this.x = x;
		this.y = y;
		this.r = r;
	}
}

public class D {
	public double get(Circle c1, Circle c2, Circle c3) {
		double r = Math.sqrt((c2.x-c3.x)*(c2.x-c3.x)+(c2.y-c3.y)*(c2.y-c3.y));
		return Math.max(c1.r, (r+c2.r+c3.r)/2);
	}
	public void run() throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter output = new PrintWriter(new File("output.txt"));
			
		int t = input.nextInt();
		
		for (int tt = 0; tt < t; tt++) {
			int n = input.nextInt();
			
			double ans = 0;
			
			Circle[] cs = new Circle[n];
			
			for (int i = 0; i < n; i++) {
				cs[i] = new Circle(input.nextInt(), input.nextInt(), input.nextInt());
			}
			
			if (n == 1) {
				ans = cs[0].r;
			}
			
			if (n == 2) {
				ans = Math.max(cs[1].r, cs[0].r);
			}
			if (n == 3) {
				ans = Math.min(get(cs[0], cs[1], cs[2]), 
						Math.min(get(cs[1], cs[0], cs[2]), 
								get(cs[2], cs[0], cs[1])));
			}
			
			output.println("Case #"+(tt+1)+": "+ans);
		}
		
		
		input.close(); output.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		(new D()).run();
	}
}