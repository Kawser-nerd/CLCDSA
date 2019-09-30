import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);  
		int n = sc.nextInt();
		List<Integer> list = new ArrayList<Integer>();
		for(int i = 0;i < n;i++) {
			list.add(sc.nextInt());
		}
		Collections.sort(list);
		list.set(n-1,list.get(n-1) / 2);
		int sum = 0;
		for(int i:list) {
			sum += i;
		}
		System.out.println(sum);
		sc.close();
	}
}