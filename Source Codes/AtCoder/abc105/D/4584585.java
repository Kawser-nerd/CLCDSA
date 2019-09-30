import java.util.Scanner;
import java.util.HashMap;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long m = sc.nextLong();
		long[] a=new long[n];
		HashMap<Long,Integer> map=new HashMap<>();
		long ans = 0;
		a[0]=sc.nextLong();
		for(int i = 1; i<n; i++){
			 a[i] = sc.nextLong()+a[i-1];
		}
		for(int i = 0; i<n; i++){
			if(map.containsKey(a[i]%m)){
				map.put(a[i]%m,map.get(a[i]%m)+1);
			}else{
				map.put(a[i]%m,1);
			}
		}
		for(long i:map.keySet()){
			long q=map.get(i);
			if(i==0){
				ans+=q;
			}
			ans+=(q*(q-1))/2;
		}
		System.out.println(ans);
	}
}