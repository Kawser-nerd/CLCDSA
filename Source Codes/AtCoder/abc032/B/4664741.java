import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<String,Integer>map=new TreeMap<>();
			String s=sc.next();
			int k=sc.nextInt();
			for(int i=0;i<s.length()-k+1;i++) {
				map.put(s.substring(i, i+k),1);
			}
			System.out.println(map.size());
	}
}