import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<Integer,Integer>map=new TreeMap();
		int a=sc.nextInt();
		int ans=0;

		for(int i=0;i<a;i++) {
			int m=sc.nextInt();
			if(map.containsKey(m))ans++;
			else map.put(m, 1);
			}
		System.out.println(ans);
		}
	} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.