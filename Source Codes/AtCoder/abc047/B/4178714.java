//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		int w = sc.nextInt(); int h = sc.nextInt(); int n = sc.nextInt();
		Point hidarisita = new Point(0,0);
		Point migiue = new Point(w,h);

		for (int i=0; i<n; i++) {
			int x = sc.nextInt(); int y = sc.nextInt(); int a = sc.nextInt();
			if (a == 1) {
				hidarisita.x = Math.max(hidarisita.x, x); 
			}
			else if (a == 2) {
				migiue.x = Math.min(migiue.x, x);
			}
			else if (a == 3) {
				hidarisita.y = Math.max(hidarisita.y, y); 
			}
			else if (a == 4) {
				migiue.y = Math.min(migiue.y, y);
			}
		}
		
		System.out.println(Math.max(0,migiue.x-hidarisita.x)*Math.max(0,migiue.y-hidarisita.y));
	}
}


class Point{
	int x;
	int y;
	Point(int x, int y) {this.x=x; this.y=y;}
}