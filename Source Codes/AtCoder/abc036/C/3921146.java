import java.util.Scanner;
import java.util.Map;
import java.util.TreeMap;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		Map<Integer,Integer> e= new TreeMap<Integer,Integer>();
		for(int i = 0; i < n; i++){
			a[i]=sc.nextInt();
			e.put(a[i],0);
		}
		int count= 0;
		for(int key:e.keySet()){
			e.put(key,count++);
		}
		for(int i = 0; i<n; i++){
			System.out.println(e.get(a[i]));
		}
	}
}