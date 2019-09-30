import java.util.*;

public class Main {
   public static void main(String[] args) {
           Scanner sc = new Scanner(System.in);
       
           int N = sc.nextInt();
           int T = sc.nextInt();
       
           int A[] = new int[N];
           
           for(int i = 0;i < N;i++){
               A[i] = sc.nextInt();
           }
           
           int max = 0;
		int maxCnt = 0;
		int min = Integer.MAX_VALUE;

		for (int i=0;i<N;i++) {
			min = Math.min(min, A[i]);
			int gain = A[i] - min;
			if (gain > max) {
				max = gain;
				maxCnt = 1;
			} else if (gain == max) {
				maxCnt++;
			}
		}

	    System.out.println(maxCnt);                                 
   
   }    
}