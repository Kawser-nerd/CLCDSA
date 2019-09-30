import java.util.Scanner;

/**
 * http://abc008.contest.atcoder.jp/tasks/abc008_3
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int c[] = new int[N];
		for(int i=0; i<N; i++) c[i] = sc.nextInt();
		sc.close();
		
		double ans = 0;
		for(int i=0; i<N; i++){
			double s = 0;
			for(int j=0; j<N; j++){
				if(c[i]%c[j] == 0 && i!=j) s++;
			}
			if(s%2==0){
				ans += (s+2.0)/(2*s+2.0); 
			}else{
				ans += 0.5;
			}
		}
		
		System.out.println(ans);

	}

}