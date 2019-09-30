import java.util.*;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	int N = input.nextInt();
      	int M = input.nextInt();
      	Map<Integer, int[]> sorted = new TreeMap<Integer, int[]>();
      
      
      	for (int i = 0; i < M; i++) {
          	int P = input.nextInt();
          	int Y = input.nextInt();
          	int[] arr = new int[2];
          	arr[0] = P;
          	arr[1] = i;
          	sorted.put(Y, arr);
        }
      	
      	String[] ans = new String[M];
      	int[] city = new int[N];
      	for (int[] arr : sorted.values()) {
        	ans[arr[1]] = String.format("%06d%06d", arr[0], ++city[arr[0]-1]);
        }
      	for (int i = 0; i < M; i++) {
			System.out.println(ans[i]);
        }
    } 	
}