import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<String,Integer>map=new TreeMap<>();
			int n=sc.nextInt();
			for(int i=0;i<n;i++) map.put(sc.next(), sc.nextInt());
			int sum=0;String ans="atcoder";
			for(Integer v:map.values()) sum+=v;
			for(String str:map.keySet()) if(map.get(str)>sum/2)ans=str;
			System.out.println(ans);
	}
}