import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        String S = sc.next();
        String T = sc.next();
        
        for (int s = 0; s < S.length(); s++) {
        	if(T.charAt(0) == S.charAt(s) && T.startsWith(S.substring(s))) {
        		System.out.println(N*2 - (S.length() - s));
        		return;
        	}
        }
        
        System.out.println(N*2);
    }
}