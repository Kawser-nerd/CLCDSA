import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] array = new int[n];
		for(int i = 0; i < n; i++) {
			int x = sc.nextInt();
			array[x-1]++;
		}
		Map<Integer, Integer> map = new HashMap<>();
		for(int i = 0; i < array.length; i++){
			if(array[i] == 0) continue;
			map.put(i, array[i]);
		}
		int sum = 0;
		List<Integer> list = map.entrySet().stream().sorted((e1, e2) -> e2.getValue() - e1.getValue()).map(e -> e.getValue()).collect(Collectors.toList());
		for(int i = 0; i < list.size(); i++){
			if(i < k) continue;
			sum += list.get(i);
		}
		System.out.println(sum);
	}
}