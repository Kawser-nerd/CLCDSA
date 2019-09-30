import java.util.*;

public class Main {
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int T = sc.nextInt();
		
		int[] tn = new int[N];
		for(int i = 0; i < N; i++){
			tn[i] = sc.nextInt();
		}

		int ans = T;
		int term = 0;
		for(int i=1; i<N; i++){
			term = tn[i]-tn[i-1];
			if(term > T){
				ans += T;
			} else{
				ans += term;
			}
		}

		System.out.println(ans);
		sc.close();
	}
}