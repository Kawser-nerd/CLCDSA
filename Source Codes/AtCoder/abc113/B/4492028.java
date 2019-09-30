import java.util.*;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	int N = input.nextInt();
      	int T = input.nextInt();
      	int A = input.nextInt();
      	double minGap = 5000;
      	int ans = 0;
      
      	for (int i = 0; i < N; i++) {
          	double avg = (double)T - 0.006 * input.nextInt();
          	if (Math.abs(A - avg) < minGap) {
            	minGap = Math.abs(A - avg);
              	ans = i + 1;
            }
        }
		
      	System.out.print(ans);
    } 	
}