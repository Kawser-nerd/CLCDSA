import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++){
			 a[i] = sc.nextInt();
		}
		int ans = 0;
		Map<Integer,Integer> b=new HashMap<Integer,Integer>();
		for(int i =0; i < n; i++){
			while(a[i]%2==0){
				a[i]/=2;
			}
			b.put(a[i],4);
		}
		System.out.println(b.size());
	}
}