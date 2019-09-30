import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int H = sc.nextInt();
        int W = sc.nextInt();
        
        int w = 0;
        for (int i = 0; i < H; i++) {
        	char[] map = sc.next().toCharArray();
        	for (int j = 0; j < W; j++) {
        		if (map[j] == '#' && w <= j) {
        			w = j;
        		} else if (map[j] == '#' && w > j) {
        			System.out.println("Impossible");
        			return;
        		}
        	}
        }
        
        System.out.println("Possible");
    }
}