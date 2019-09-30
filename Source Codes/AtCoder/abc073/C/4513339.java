import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int n = Integer.parseInt(s);
		HashSet<Integer> set = new HashSet<Integer>();
		
		for (int i = 0; i < n; i++) {
			s = br.readLine();
			int a = Integer.parseInt(s);
			if(set.contains(a))
				set.remove(a);
			else
				set.add(a);
		}
		//boolean[] nums = new boolean[1000000000];
//		
//		int max = 0;
//		for (int i = 0; i < n; i++) {
//			int number = Integer.parseInt(ss[i]);
//			if(number > max)
//				max = number;
//			if(nums[number])
//				nums[number]=false;
//			else {
//				nums[number] = true;
//			}
//		}
//		int count = 0;
//		for (int i = 0; i <= max; i++) {
//			if(nums[i])
//				count++;
//		}
		System.out.println(set.size());
		

	}

}