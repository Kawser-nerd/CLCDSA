import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		double[] w = new double[n];
		double[] p = new double[n];
		double pmax = 0;
		for(int i=0; i<n; i++){
			w[i] = sc.nextDouble();
			p[i] = sc.nextDouble();
			pmax = Math.max(pmax, p[i]);
		}
		double low = 0;
		double upp = pmax;
		double x = (low + upp) / 2;
		while(upp-low>0.00000001){
			double[] c = new double[n];
			for(int i=0; i<n; i++){
				c[i] = w[i] * (p[i] - x);
			}
			Arrays.sort(c);
			double sum = 0;
			for(int i=n-1; i>=n-k; i--){
				sum += c[i];
			}

			if(sum>0){
				low = x;
				x = (low + upp) / 2;
			}
			else{
				upp = x;
				x = (low + upp) / 2;
			}
		}
		System.out.println(x);
	}
}