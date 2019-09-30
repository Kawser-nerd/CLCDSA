import java.util.*;

public class Main{
	public static void main(String[] args){
            
           Scanner sc = new Scanner(System.in);
		                                        
           int   N = sc.nextInt();
           
           int h[] = new int[N+1];
           
           for(int i = 1;i <=N;i++){
               h[i] = sc.nextInt();
           }
           
           if (N == 1) {
			System.out.println(1);
			return;
		}

		int state = h[1] > h[0] ? 1 : -1;
		int s = 1;
		int t = 1;
		int u = 1;
		
		int max = 0;
		for (int i = 2; i <= N; i ++) {
			if (state > 0) {
				if (h[i] > h[i - 1]) {
					t = i;
					u = i;
				} else {
					u = i;
					state = -state;
				}
			} else {
				if (h[i] < h[i - 1]) {
					u = i;
				} else {
					state = -state;
					
					int size = u - s + 1;
					max = Math.max(max, size);
					
					s = i - 1;
					t = i - 1;
				}
			}
		}
		max = Math.max(max, u - s + 1);
		System.out.println(max);      
           
	}
}