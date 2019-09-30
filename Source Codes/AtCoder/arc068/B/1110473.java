import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int count = 0;
		HashSet<Integer> set = new HashSet<>();
		for(int i=0;i<n;i++){
			int a = in.nextInt();
			if(set.contains(a)) count++;
			else set.add(a);
		}
		System.out.println(n-(count + (count % 2 == 0 ? 0 : 1)));
	}
}