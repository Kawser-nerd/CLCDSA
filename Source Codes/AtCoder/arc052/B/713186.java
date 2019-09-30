import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		solve2();
		
	}

	private static void solve2() {
		Scanner scn = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int N = scn.nextInt();
		int Q = scn.nextInt();
		double[] v = new double[200001];
		for(int k=0;k<N;k++){
			int X = scn.nextInt();
			int R = scn.nextInt();
			int H = scn.nextInt();
			double tmpr=R;
			for(int s=X;s<X+H;s++){
				
				v[s]+=(tmpr*tmpr+tmpr*(tmpr-(double)R/H)+(tmpr-(double)R/H)*(tmpr-(double)R/H))*Math.PI/3;
				tmpr-=(double)R/H;
			}
		}
		for(int k=0;k<Q;k++){
			int A = scn.nextInt();
			int B = scn.nextInt();
			double tmp=0;
			for(int s=A;s<B;s++){
				tmp+=v[s];
			}
			pw.println(tmp);
		}
		pw.flush();
		scn.close();
	}

}