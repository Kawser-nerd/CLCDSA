import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
 
/**
 * http://abc032.contest.atcoder.jp/tasks/abc032_b
 */
public class Main {
 
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int k = sc.nextInt();
		sc.close();
		
		Set<String> list = new HashSet<>();
		
		for(int i=0; i<=s.length()-k; i++){
			String p = s.substring(i, i+k);
			if(!list.contains(p)){
				list.add(p);
			}
		}
		
		System.out.println(list.size());
 
	}
 
}