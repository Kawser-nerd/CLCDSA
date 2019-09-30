import java.util.Scanner;

/**
 * http://abc016.contest.atcoder.jp/tasks/abc016_4
 * ????
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final Coord A = new Coord(sc.nextInt(), sc.nextInt());
		final Coord B = new Coord(sc.nextInt(), sc.nextInt());
		final int N = sc.nextInt();
		Coord[] c = new Coord[N];
		for(int i=0; i<N; i++){
			c[i] = new Coord(sc.nextInt(),sc.nextInt());
		}
		sc.close();
		
		int count = 0;
		for(int i=0; i<N; i++){
			if(isIntersect(A.x,A.y,B.x,B.y,c[i].x,c[i].y, c[(i+1)%N].x,c[(i+1)%N].y)){
				count++;
			}
		}
		
		System.out.println(count/2+1);

	}
	
	static boolean isIntersect (double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
		double ta = (cx-dx)*(ay-cy) + (cy-dy)*(cx-ax);
		double tb = (cx-dx)*(by-cy) + (cy-dy)*(cx-bx);
		double tc = (ax-bx)*(cy-ay) + (ay-by)*(ax- cx);
		double td = (ax-bx)*(dy-ay) + (ay-by)*(ax-dx);
		return tc*td < 0 && ta*tb < 0;
	};
	
	static class Coord{
		int x;
		int y;
		Coord(final int x, final int y){
			this.x = x;
			this.y = y;
		}
	}

}