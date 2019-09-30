import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	Map<String, Integer> map = new TreeMap<String, Integer>();
    	int N=sc.nextInt();

    	for(int i=1;i<=N;i++) {
    		String s=sc.next();
    		if(map.containsKey(s))map.put(s,map.get(s)+1);
    		else map.put(s, 1);
    	}
    	int M=sc.nextInt();
    	for(int i=1;i<=M;i++) {
    		String s=sc.next();
    		if(map.containsKey(s))map.put(s,map.get(s)-1);
    		else map.put(s, -1);
    	}
    	int ans=0;
    	for(int val : map.values()){
    		ans=Math.max(ans,val);
    	 }
    	System.out.println(ans);
	}
}