import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int[] map = new int[5];
        for (int i = 0; i < 5; i++) {
        	map[i] = sc.nextInt();
        }
        
        List<Integer> list = new ArrayList<>(100000);
        for (int i = 0; i < 5; i++) {
        	for (int j = i+1; j < 5; j++) {
        		for (int k = j+1; k < 5; k++) {
        			list.add(map[i] + map[j] + map[k]);
        		}
        	}
        }
        
        list = list.stream().distinct().sorted().collect(Collectors.toList());
        
        System.out.println(list.get(list.size()-3));
    }
    
}