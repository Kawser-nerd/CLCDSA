import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			int N = sc.nextInt();
			int K = sc.nextInt();
			double U = sc.nextDouble();
			double[] P =new double[N];
			for(int a=0;a<N;a++){
				P[a]=sc.nextDouble();
			}
			Arrays.sort(P);
			
			boolean flag = false;
			for(int a=1;a<N;a++){
				double delta = 0;
				for(int b=0;b<a;b++){
					delta += P[a]-P[b];
				}
				if(delta>U){
					delta = U;
					flag=true;
				}
				U-=delta;
				delta/=(a);
				for(int b=0;b<a;b++){
					P[b]+=delta;
				}
				
				if(flag)break;
			}
			
			
			for(int a=0;a<N;a++){
				P[a]=Math.min(1.0, P[a] + (U/N));
			}
			
			double ans = 1;
			
			for(int a=0;a<N;a++){
				System.out.print(P[a]+" ");
				ans *= P[a];
			}
			System.out.println();
			
			System.out.printf("Case #%d: %.12f%n", t, ans);
			out.printf("Case #%d: %.12f%n", t, ans);
		}
		out.close();
	}
}
