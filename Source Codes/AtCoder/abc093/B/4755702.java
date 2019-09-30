import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		TreeSet<Integer> set = new TreeSet<>();
		for (int i=a; i<=Math.min(b,a+k-1); i++) set.add(i);
		for (int i=b; i>=Math.max(a,b-k+1); i--) set.add(i);
		set.forEach(out::println);
	}
}