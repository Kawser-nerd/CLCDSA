import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);        
        
        int N = sc.nextInt();
        
        int[] map = new int[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
		}
		
		map = Arrays.stream(map).filter(i -> i > 0).toArray();
		
		double sum = 0;
		for (int bug: map) {
			sum += bug;
		}
		
		System.out.println((int)(Math.ceil(sum/map.length)));
    }
}