import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;



public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int n = sc.nextInt();
		
		HashMap<Integer, TreeSet<Integer>> map = new HashMap<>();
		for (int i=1;i<=h;i++) {
			map.put(i, new TreeSet<>());
		}
		
		for (int i=0;i<n;i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			map.get(x).add(y);
		}
		
		int yMax = 1;
		for (int i=2;i<=h;i++) {
			//System.out.println((i-1)+" "+yMax);
			if (map.get(i).isEmpty()) {
				yMax++;
			} else if (map.get(i).first()<=yMax) {
				System.out.println(i-1);
				return;
			} else if (map.get(i).first()>yMax+1) {
				yMax++;
			}
		}
		System.out.println(h);
	}

}