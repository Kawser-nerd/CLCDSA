import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class  Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] tall = new int[n];

		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
			for(int i=0; i<n; i++) {
				tall[i]=sc.nextInt();
				map.put(tall[i], i+1);
			}
			Arrays.sort(tall);
				//??
				for(int j=tall.length-1; j>=0; j--) {
					System.out.println(map.get(tall[j]));
				}
	}

}