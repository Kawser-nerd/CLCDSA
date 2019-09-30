import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        char[] s = sc.next().toCharArray();
        
        List<Integer> list = new ArrayList<>(s.length);
        int mul = 1;
        boolean lock = false;
        for (int i = 0; i < s.length; i+=2) {
        	if (i+1 < s.length) {
        		if (s[i+1] == '+') {
        			if (lock) {
        				mul*=Character.getNumericValue(s[i]) == 0 ? 0 : 1;
        				list.add(mul);
        				lock = false;
        				mul = 1;
        			} else {
            			list.add(Character.getNumericValue(s[i]));
        			}
        			
        		} else {
        			mul*=Character.getNumericValue(s[i]) == 0 ? 0 : 1;
        			lock = true;
        		}
        	} else if (lock) {
        		mul*= Character.getNumericValue(s[i]) == 0 ? 0 : 1;
        		list.add(mul);
        		lock = false;
        		mul = 1;
        	} else {
        		list.add(Character.getNumericValue(s[i]));
        	}
        }
        
        int ans = 0;
        for (int a : list) {
        	if (a != 0) {
        		ans++;
        	}
        }
        System.out.println(ans);
    }
    
}