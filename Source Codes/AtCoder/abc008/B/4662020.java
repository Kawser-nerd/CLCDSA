import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
public class Main {
	static long N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<String,Integer>map=new TreeMap<>();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			String s=sc.next();
			if(map.containsKey(s))map.put(s, map.get(s)+1);
			else map.put(s,1);
		}
		int max=0;String Max="";
		for (String c1 : map.keySet()) {
			if(max<map.get(c1)) {
				max=map.get(c1);
				Max=c1;
			}
		}
		System.out.println(Max);

	}
}