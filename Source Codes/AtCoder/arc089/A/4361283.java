import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int nextInt () {return Integer.parseInt(sc.next());}
	static int[] nextIntArray (int n) {return IntStream.range(0,n).map(i->nextInt()).toArray();}
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static String yesno (boolean b) {return b?"Yes":"No";}
	public static void main(String[] args) {
		
		int n = nextInt();
		int x = 0, y = 0; long tSum = 0;
		boolean F = true;
		for (int i=0; i<n; i++) {
			long t = nextInt() - tSum;
			tSum += t;
			int tempX = nextInt();
			int tempY = nextInt();
			if (x==tempX && y==tempY) {
				F = false; break;
			}
			
			int dist = calcManhatDistance(x,y,tempX,tempY);
			
//			System.out.println(dist%2+":"+t%2);
			
			if (dist>t || dist%2!=t%2) {
				F = false; break;
			}
			x = tempX; y = tempY;
		}
		
		System.out.println(yesno(F));
		
	}
	
	static int calcManhatDistance (int x1, int y1, int x2, int y2) {
		int d = Math.abs(x1-x2)+Math.abs(y1-y2);
		return d;
	}
	static double calcEuclidDistance (double x1, double y1, double x2, double y2) {
		double d = Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		return d;
	}
	
}