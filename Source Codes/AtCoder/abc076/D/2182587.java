import java.util.Scanner;

/**
 * https://abc076.contest.atcoder.jp/tasks/abc076_c
 */
public class Main {

	public static void main(String[] args) throws Exception {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		double[] t = new double[N];
		double[] v = new double[N];
		for(int i=0; i<N; i++) t[i] = sc.nextDouble();
		for(int i=0; i<N; i++) v[i] = sc.nextDouble();
		sc.close();
	
		v[N-1] = Math.min(v[N-1],t[N-1]);
		for(int i=N-2; i>=0; i--){
			v[i] = Math.min(v[i], v[i+1]+t[i]);
		}
		
		double ans = 0;
		double current = 0;
		for(int i=0; i<N; i++){
			double next = i==N-1 ? 0 : v[i]<v[i+1] ? v[i] : v[i+1];
			double maxV = 0;
			double previous = current;
			if(current+t[i]<=next){
				maxV = current+t[i];			
				current = maxV;
			}else{
				maxV = Math.min(v[i], (current+next+t[i])/2);
				ans -= (maxV-next)*(maxV-next)/2;
				current = next;
			}
			ans += maxV*t[i];
			ans -= (maxV-previous)*(maxV-previous)/2;
		}
		System.out.println(ans);
	}

}