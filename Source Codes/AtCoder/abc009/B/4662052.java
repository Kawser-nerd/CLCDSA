import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
public class Main {
	static long N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<Integer,Integer>map=new TreeMap<>();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a =sc.nextInt();
			map.put(a, a);
		}
		int max=0;int second=0;
		for (int c1 : map.keySet()) {
			if(max<map.get(c1)) {
				second=max;
				max=c1;
			}
		}
		System.out.println(second);

	}
}