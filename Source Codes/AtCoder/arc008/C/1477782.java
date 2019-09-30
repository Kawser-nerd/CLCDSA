import java.util.Scanner;
import java.util.Arrays;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);;
		int n = scan.nextInt();
		int[] x = new int[n],y = new int[n],t = new int[n],r = new int[n];
		for(int i = 0;i < n;i++) {
			x[i] = scan.nextInt();y[i] = scan.nextInt();t[i] = scan.nextInt();r[i] = scan.nextInt();
		}
		scan.close();
		if(n == 1) {
			System.out.println(0.0);
			return;
		}
		double[][] G = new double[n][n];
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				G[i][j] = Math.sqrt((double)Math.pow(x[i] - x[j],2.0) + (double)Math.pow(y[i] - y[j],2.0)) / (double)Math.min(t[i],r[j]);//i??j?????????
		double[] d = daikd(G,0);
		Arrays.sort(d);
		double max = 0.0;
		for(int i = 1;i < n;i++)
			max = Math.max(max,d[i] + n - i - 1);
		System.out.printf("%10.10f\n",max);
		
	}
	static double[] daikd(double[][] G,int start) {
		int n = G.length;
		double[] d = new double[n];
		boolean[] used = new boolean[n];
		for(int i = 0;i < n;i++) {
			d[i] = 1000000000000.0;
			used[i] =false;
		}
		d[start] = 0.0;
		while(true){
	        int v = -1;
	        for(int u = 0;u < n;u++){
	            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
	        }

	        if(v == -1)break;

	        used[v] = true;

	        for(int u = 0;u < n;u++)
	            d[u] = Math.min(d[u],d[v] + G[v][u]);
	    }
		return d;
	}
}