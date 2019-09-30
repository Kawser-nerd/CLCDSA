import java.math.BigDecimal;
import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		BigDecimal sum = BigDecimal.ZERO;
		List<Entry<Integer, Integer>> list = new ArrayList<>();
		for(int i =0; i < n; i++)
			list.add(new SimpleEntry<Integer,Integer>(sc.nextInt(), sc.nextInt()));
		
		list = list.stream()
				.sorted(Comparator.comparingInt(entry -> entry.getKey()))
				.collect(Collectors.toList());
		
		for(Entry<Integer, Integer> entry : list) {
			if(m == 0)
				break;
			
			BigDecimal a = BigDecimal.valueOf(entry.getKey());
			BigDecimal b = BigDecimal.valueOf(entry.getValue());

			if(m > entry.getValue()) {
				m-= entry.getValue();
				sum = sum.add(a.multiply(b));
			}else if(m <= entry.getValue()) {
				b = BigDecimal.valueOf(m);
				sum = sum.add(a.multiply(b));
				
				m = 0;
			}
		}
		
		System.out.println(sum.toString());
	}
}