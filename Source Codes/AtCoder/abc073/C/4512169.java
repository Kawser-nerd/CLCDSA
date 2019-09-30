import java.util.HashMap;
import java.util.HashSet;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < n; i++) {
			int m = scan.nextInt();
			if(set.contains(m)){
				if(mp.containsKey(m)){
					int value=mp.get(m);
					mp.put(m, value+1);
				}else{
					mp.put(m, 1);//????
				}
			}
			set.add(m);

		}
		int count=0;
		for (Entry<Integer, Integer> entry : mp.entrySet()) {
            Integer key = entry.getKey();
            Integer value = entry.getValue();
            if(value%2==1){
            	count++;
            }
          
        }
		System.out.println(set.size()-count);
	}
}