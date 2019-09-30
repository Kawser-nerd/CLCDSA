import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int C = in.nextInt();
		Map<Integer,List<int[]>> map = new HashMap<>();
		for(int i=1;i<=C;i++) {
			List<int[]> list = new ArrayList<>();
			map.put(i, list);
		}
		for(int i=0;i<n;i++) {
			int[] tmp = {in.nextInt(),in.nextInt()};
			int c = in.nextInt();
			map.get(c).add(tmp);
		}
		int[] time = new int[100002];
		for(int i=1;i<=C;i++) {
			List<int[]> list = map.get(i);
			list.sort((st1,st2)->st1[0]-st2[0]);
			int last = 0;
			for(int[] st:list) {
				if(last==st[0]) {
					time[last+1]++;
					time[st[1]+1]--;
					last = st[1];
				}else {
					time[st[0]]++;
					time[st[1]+1]--;
					last = st[1];
				}
			}
		}
		
		for(int i=1;i<=100001;i++) {
			time[i] += time[i-1];
		}
		int max = 0;
		for(int i=1;i<=100001;i++) {
			max = Math.max(max, time[i]);
		}
		System.out.println(max);
		in.close();

	}

}