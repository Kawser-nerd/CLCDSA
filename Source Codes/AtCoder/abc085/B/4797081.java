import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashSet<Integer> set = new HashSet<Integer>();
		for(int i = 0; i < n; i++) {
			int number = sc.nextInt();
			set.add(number);
		}
		System.out.println(set.size());
		
	}
}