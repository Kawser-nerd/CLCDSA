import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		Map<String,Integer>map=new TreeMap<>();
		String s=sc.next();
		String A[]= {"A","B","C","D","E","F"};
		for(int i=0;i<6;i++)map.put(A[i],0);
		for(int i=0;i<s.length();i++) {
			String S=s.substring(i,i+1);
			map.put(S,map.get(S)+1);
		}
		System.out.println(map.get("A")+" "+map.get("B")+" "+map.get("C")+" "+map.get("D")+" "+map.get("E")+" "+map.get("F"));
	}
}