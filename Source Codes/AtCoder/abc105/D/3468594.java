import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		long count = 0;
		Map<Long, Integer> map = new HashMap<>();
		map.put(0L, 1);
		long a = 0;
		for (int i=0;i<n;i++){
			a += sc.nextInt();
			Integer num = map.get(a%m);
			if (num!=null) {
				count+=num;
				map.put(a%m, num+1);
			} else
				map.put(a%m, 1);
		}
		System.out.println(count);
		
	}

}