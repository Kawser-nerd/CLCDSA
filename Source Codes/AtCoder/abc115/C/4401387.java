import java.util.Scanner;
import java.util.Arrays;
public class Main { 
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
      	int N = reader.nextInt();
      	int K = reader.nextInt();
      	int[] h = new int[N];
      	for (int i = 0; i < N;i++) {
        	h[i] = reader.nextInt();
        }
      Arrays.sort(h);
      int min = h[N-1] - h[0];
      for (int i = 0; i < N - K + 1;i++) {
        	int gap = h[i + K -1] - h[i];
        	if (min > gap) {
            	min = gap;
            }
        }
      
      System.out.print(min);
      
      
		
    }
}