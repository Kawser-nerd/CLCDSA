import java.util.Scanner;
import java.util.TreeMap;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		TreeMap<Long,Long> g=new TreeMap<Long,Long>();
		long[] aa=new long[n];
		long[] bb = new long[n];
		long sum = 0;
		for(int i = 0; i < n; i++){
			long a = sc.nextLong();
			long b = sc.nextInt();
			aa[i]=a;
			bb[i]=b;
			if(!g.containsKey(aa[i])){
				g.put(aa[i],bb[i]);
			}else{
				g.put(aa[i],bb[i]+g.get(aa[i]));
			}
		}
		for(long i :g.keySet()){
			sum+=g.get(i);
			if(sum>=k){
				System.out.println(i);
				return;
			}
		}
	}
}