import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int[] map = new int[N];
        for (int i = 0; i < N; i++) {
        	map[i] = sc.nextInt();
        }
        
        int count = 0;
        int index = 1;
        while(true) {
        	if (map[index-1] == 2) {
        		count++;
        		System.out.println(count);
        		return;
        	} else {
        		count++;
        		index = map[index-1];
        	}
        	
        	if (count > N) {
        		System.out.println(-1);
        		return;
        	}
        }
    }
    
}