import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int D = sc.nextInt();
		int E = sc.nextInt();
		int F = sc.nextInt();
		sc.close();
		ArrayList<Integer> x = new ArrayList<Integer>();
		for(int i=0; i*A*100<=F; i++) {
			for(int j=0; j*B*100<=F; j++) {
				x.add(100*A*i+100*B*j);
			}
		}
		ArrayList<Integer> y = new ArrayList<Integer>();
		for(int i=0; i*C<=F; i++) {
			for(int j=0; j*D<=F; j++) {
				y.add(C*i+D*j);
			}
		}
		int maxtotal = 100*A;
		int maxs = 0;
		double maxper = 0;
		for(int i=0; i<x.size(); i++) {
			for(int j=0; j<y.size(); j++) {
				int amounts = y.get(j);
				int amountw = x.get(i);
				if(amounts == 0 && amountw == 0) continue;
				if(amounts+amountw<=F && 100*amounts <= E*amountw) {
					if((double)amounts/(double)(amounts+amountw) > maxper) {
						maxtotal = amounts + amountw;
						maxs = amounts;
						maxper = (double)(amounts)/(amounts+amountw);
					}
				}
			}
		}
//		OUTER: for(int a=0; a<=N; a++) {
//			OUTERb: for(int b=0; b<=N; b++) {
//				if(A*a+B*b > F/100) break OUTERb;
//				INNER: for(int c=0; c<=N; c++) {
//					int d = N - a - b - c;
//					if(d < 0) break INNER;
//					if(C*c + D*d>F*E/(100+E)) break INNER;
//					if(((A*a+B*b)*E >= C*c+D*d) && (100*A*a+100*B*b+C*c+D*d <= F)) {
//						int temptotal = 100*A*a + 100*B*b+C*c+D*d;
//						int temps = C*c + D*d;
//						double tempper = (double)(100*temps)/temptotal;
//						if(maxper < tempper) {
//							maxtotal = temptotal;
//							maxs = temps;
//							maxper = tempper;
//						}
//					}
//				}
//			}
//		}
		System.out.println(maxtotal + " " + maxs);
	}

}