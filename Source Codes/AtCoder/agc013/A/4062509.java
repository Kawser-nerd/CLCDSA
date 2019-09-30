import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        long ans = 0;
        int start = sc.nextInt();
        boolean up = false;
        boolean down = false;
        for (int i = 1; i < N; i++) {
        	int a = sc.nextInt();
        	if (start == a)
        		continue;
        	
        	if (start > a) {
        		if (up) {
        			ans++;
        			down = false;
        			up = false;
        		} else {
        			down = true;
        		}
        	} else {
        		if (down) {
        			ans++;
        			up = false;
        			down = false;
        		} else {
        			up = true;
        		}
        	}
        	
        	start = a;
        }
        
        System.out.println(ans+1);
    }
}