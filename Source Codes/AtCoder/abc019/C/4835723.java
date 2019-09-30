import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<Long,Integer>map=new HashMap<>();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			long a=sc.nextLong();
			while(a%2==0) {
				a/=2;
			}
			map.put(a, 0);
		}
		System.out.println(map.size());
	}
}