import java.util.Scanner;

/**
 * http://abc026.contest.atcoder.jp/tasks/abc026_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int A = sc.nextInt();
		final int B = sc.nextInt();
		final int C = sc.nextInt();
		sc.close();
		
		double minT = (double)(100-B)/(double)A;
		double maxT = (double)(100+B)/(double)A;
		double ans;
		while(true){
			double t = (minT+maxT)/2;
			double f = A*t + B*Math.sin(C*t*Math.PI);
			if(Math.abs(100-f)<0.0000001){
				ans = t;
				break;
			}else if(f<100){
				minT=t;
			}else{
				maxT=t;
			}
			
		}

		System.out.println(ans);
		
	}

}