import java.util.Arrays;
import java.util.Scanner;


/**
 * http://abc033.contest.atcoder.jp/tasks/abc033_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		Point[] pos = new Point[N];
		for(int i=0; i<N; i++) pos[i] = new Point(i,sc.nextInt(), sc.nextInt());
		sc.close();
		
		long acuteAngle = 0; //??
        long rightAngle = 0; //??
        long obtuseAngle = 0; //??
		for(int i=0; i<N; i++){
			double[] angles = new double[(N-1)*2];
			int tmpJ=0;
			for(int j=0; j<N; j++){
				if(j==i) continue;
				angles[tmpJ++] = getAngle(pos[i], pos[j]);
			}
			for(int j=0; j<N-1; j++){
				angles[tmpJ++] = angles[j]+Math.PI*2;
			}
			
			Arrays.sort(angles);
			for(int j=0; j<N-1; j++){
				int t1=0;
				for (int k = 0; k < tmpJ && angles[t1] < angles[j]+Math.PI/2-1e-9; ++k) {				
                    ++t1;
                }
                int t2=t1;
                for (int k = t1; k < tmpJ && angles[t2] < angles[j]+Math.PI/2+1e-9; ++k) {
                    ++t2;
                }
                int t3=t2;
                for (int k = t2; k < tmpJ && angles[t3] < angles[j] + Math.PI-1e-9; ++k) {
                    ++t3;
                }
                rightAngle += t2-t1;
                obtuseAngle += t3-t2;
			}
			
		}
		
		acuteAngle = (long)N*(N-1)*(N-2)/6-rightAngle-obtuseAngle;
		
		System.out.printf("%d %d %d%n", acuteAngle, rightAngle, obtuseAngle);
	}
	

	
	static class Point{
		int x;
		int y;
		int id;
		Point(int id, int x, int y){
			this.id = id;
			this.x = x;
			this.y = y;
		}			
	}
	
	static double getAngle(Point a, Point b){
		double d = Math.atan2(b.y-a.y,b.x-a.x);
		if(d<0) d += Math.PI*2;
		return d;
	}
	

}