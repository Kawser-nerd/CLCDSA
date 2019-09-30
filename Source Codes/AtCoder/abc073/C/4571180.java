import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
 
public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int t ;
		Set<Integer> set = new HashSet<Integer>();
		while(n-- !=0) {
			t = sc.nextInt();
			if(set.contains(t))
				set.remove(t);
			else
				set.add(t);
		}
		System.out.println(set.size());
	}	
}