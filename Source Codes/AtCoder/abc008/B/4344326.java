import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        Map<String,Integer> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
        	String key = sc.next();
        	
        	if (!map.containsKey(key))
        		map.put(key, 1);
        	else
        		map.put(key, map.get(key)+1);
        }
        
        int max = 0;
        String ans = "";
        for (String key : map.keySet()) {
        	int count = map.get(key);
        	if (count > max) {
        		ans = key;
        		max = count;
        	}
        }
        
        System.out.println(ans);
    }
}