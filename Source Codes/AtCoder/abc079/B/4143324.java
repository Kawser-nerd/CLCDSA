import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        long[] map = new long[N+1];
        map[0] = 2;
        map[1] = 1;
        for (int i = 2; i <= N; i++) {
        	map[i] = map[i-2] + map[i-1];
        }
        
        System.out.println(map[N]);
    }
    
}