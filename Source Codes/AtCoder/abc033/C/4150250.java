import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        String[] map = s.split("\\+");
        
        int ans = 0;
        for (String sub: map) {
        	if (sub.replaceAll("0", "").length() == sub.length()) {
        		ans++;
        	}
        }
        System.out.println(ans);
    }
    
}