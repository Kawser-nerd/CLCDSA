import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main{
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		Map<Integer,Integer>map=new TreeMap<>();
		String ans="yes";boolean sold=true;
		int t=sc.nextInt();
		int n=sc.nextInt();int a[]=new int[n];
		for(int i=0;i<n;i++)map.put(i,sc.nextInt());
		int m=sc.nextInt();//int b[]=new int[m];
		for(int i=0;i<m;i++) {
			int b=sc.nextInt();
			sold=false;
			for(int j:map.keySet()) {
				if(map.get(j)>=b-t&&map.get(j)<=b) {
					map.remove(j);
					sold=true;
					break;
				}
			}
			if(sold!=true)ans="no";
		}
		System.out.println(ans);
	}
}