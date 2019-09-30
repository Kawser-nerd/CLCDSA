import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();

		TreeMap<Long, Integer> map = new TreeMap<>();
			for(int i = 0 ; i < N ; i++){
				long cost = sc.nextLong();
				int num = sc.nextInt();
				//map.put(cost,num);
				map.put(cost,map.containsKey(cost)?num+map.get(cost):num);
				//map.compute(cost, (k,v) -> v==null? num : num+v);
			}
			sc.close();


			long totalcost = 0;
			int bought = 0;

			for(Map.Entry<Long,Integer> kv : map.entrySet()){
				long cost = kv.getKey();
				int maxnum = kv.getValue();

				int buycount = Math.min(maxnum, M-bought);
				totalcost += buycount * cost;
				bought += buycount;

				if(bought > M){
					break;
				}
			}
			System.out.println(totalcost);
	}

}