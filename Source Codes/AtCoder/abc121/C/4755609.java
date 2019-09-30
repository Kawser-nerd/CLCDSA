import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<Long,Integer>map=new TreeMap<>();
		int n=sc.nextInt();int m=sc.nextInt();

		for(int i=0;i<n;i++) {
		long a=sc.nextLong(); int b=sc.nextInt();
		map.put(a,map.containsKey(a)?b+map.get(a):b);
		}
		long ans=0;
		for(long i:map.keySet()) {
			if(m<=map.get(i)) {
				ans+=i*m;
				break;
			}else {
				m-=map.get(i);
				ans+=i*map.get(i);
			}
		}
		System.out.println(ans);
	}
}