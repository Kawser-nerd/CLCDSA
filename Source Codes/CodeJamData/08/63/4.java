import java.util.*;
class Main{
	static int V = 32;
	public static void main(String [] argv){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i <= n; i++){
			System.out.printf("Case #%d: ", i);
			solve(sc);
		}
	}
	public static void solve(Scanner sc){
		int m = sc.nextInt();
		double p = sc.nextDouble();
		int x = sc.nextInt() / (1000000/32);
		double [] v = new double [V + 1];
		for(int i = 0; i < V/2; i++){
			v[i] = 0.;
		}
		for(int i = V/2; i < V; i++){
			v[i] = p;
		}
		v[V] = 1.;
		m--;
		while(m > 0){
			double [] next = new double[V+1];
			for(int i = 0; i <= V; i++){
				double tmp = 0.;
				for(int bet = 0; bet <= i && i + bet <= V ; bet++){
					double poss = p * v[(i+bet)] + (1-p) * v[i-bet];
					if(poss > tmp){
						tmp = poss;
					}
				}
				next[i] = tmp;
			}
			v = next;
			m--;

		}
		System.out.printf("%.06f\n", v[x]);
	}
}
