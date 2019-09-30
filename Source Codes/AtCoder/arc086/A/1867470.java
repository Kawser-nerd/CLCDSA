import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingDeque;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static char c;
	public static void main(String[] args) throws Exception {
		int k=sc.nextInt();
		int max=sc.nextInt();
		int[] arr=new int[k];
		Map<Integer,Integer> m=new HashMap<Integer,Integer>();
		for(int i=0;i<arr.length;i++){
			int number=sc.nextInt();
			int count=m.getOrDefault(number, 0);
			m.put(number, count+1);
		}
		List<int[]> list=new ArrayList<int[]>();
		for(int i:m.keySet())
			list.add(new int[]{i,m.get(i)});
		Collections.sort(list,((i1,i2)->(i1[1]-i2[1])));
		int count=0;
		for(int i=0;i<list.size()-max;i++){
			count+=list.get(i)[1];
		}
		System.out.println(count);
		
		
		
	}

}