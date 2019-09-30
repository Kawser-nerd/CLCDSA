import java.util.Scanner;

/**
 * http://abc022.contest.atcoder.jp/tasks/abc022_d
 */
public class Main {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		Pos<Integer>[] a = new Pos[N];
		Pos<Integer>[] b = new Pos[N];
		for(int i=0; i<N; i++) a[i] = new Pos<Integer>(i,sc.nextInt(),sc.nextInt());
		for(int i=0; i<N; i++) b[i] = new Pos<Integer>(i,sc.nextInt(),sc.nextInt());
		sc.close();
		
		Pos<Double> aCenter = new Pos<Double>(0,0.0,0.0);
		Pos<Double> bCenter = new Pos<Double>(0,0.0,0.0);
		
		for(int i=0; i<N; i++){
			aCenter.x += a[i].x;
			aCenter.y += a[i].y;
			bCenter.x += b[i].x;
			bCenter.y += b[i].y;
		}
		
		aCenter.x/=N;
		aCenter.y/=N;
		bCenter.x/=N;
		bCenter.y/=N;
		
		double aMaxLen = 0.0;
		double bMaxLen = 0.0;
		for(int i=0; i<N; i++){
			aMaxLen = Math.max(aMaxLen, getDistance(new Pos<Double>(0,(double)a[i].x,(double)a[i].y),aCenter));
			bMaxLen = Math.max(bMaxLen, getDistance(new Pos<Double>(0,(double)b[i].x,(double)b[i].y),bCenter));
		}
		
		System.out.println(bMaxLen/aMaxLen);

	}
	
	static class Pos<T>{
		T x;
		T y;
		int id;
		Pos(int id, T x, T y){
			this.id = id;
			this.x = x;
			this.y = y;
		}			
	}
	
	static double getDistance(Pos<Double> a, Pos<Double> b){
		return Math.sqrt(Math.pow(a.x-b.x,2) + Math.pow(a.y-b.y,2));
	}

}