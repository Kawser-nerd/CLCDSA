import java.util.HashMap;
import java.util.Scanner;

class Main{



	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[n+1];
		for(int i = 1;i <= n;i++){
			a[i] = sc.nextInt();
		}

		//		System.out.println();
		long[] sum = new long[n+1];
		for(int i = 1;i <= n;i++){
			sum[i] = a[i] + sum[i-1];
		}
		//		for(int i = 1; i<=n;i++){
		//			System.out.println(sum[i] + " " + sum[i]%m);
		//		}
		HashMap<Long, Integer> map = new HashMap<Long,Integer>();
		for(int i = 1; i<=n;i++){
			map.put(sum[i]%m, 0);
		}


		//		System.out.println();
		for(int i = 1; i<=n;i++){
			int x = map.get(sum[i]%m);
			map.put(sum[i]%m, x+1);
		}

		long ans = 0;
		if(map.containsKey(0l)){
			ans = map.get(0l);
		}
		for(long i:map.keySet()){
			if(map.get(i) >= 2){
				for(int j = map.get(i);j > 1;j--){
					ans += j-1;
				}
			}
		}
		System.out.println(ans);




	}


}

class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return from - otherpair.from;
	}
}