import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        boolean[] map = new boolean[101];
        for (int i = 0; i < 3; i++) {
        	map[sc.nextInt()] = true;
        }
        
        int ans = 0;
        for (boolean b : map) {
        	ans +=b?1:0;
        }
        
        System.out.println(ans);
    }
}