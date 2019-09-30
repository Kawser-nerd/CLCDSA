import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<Integer,Integer>map=new TreeMap();
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int d=sc.nextInt();
		for(int i=0;i<d;i++)map.put(sc.nextInt(), 1);
		System.out.println(map.size()==d&&map.containsKey(b)==false&&map.containsKey(c)==false?"YES":"NO");
	}
	} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.