import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] name = new String[n];
		int[] jinkou =  new int[n];

		HashMap<Integer,String> map = new HashMap<Integer,String>();
			for(int i=0; i<n; i++) {
				name[i] = sc.next();
				jinkou[i] = sc.nextInt();
				map.put(jinkou[i], name[i]);
			}

			int max = jinkou[0];
			int total = 0;
			//????????????
			for(int j=0; j<jinkou.length; j++) {
				total += jinkou[j];
				if(max<jinkou[j])
					max = jinkou[j];
			}
			if((total/2) < max) {
				System.out.println(map.get(max));
			}else {
				System.out.println("atcoder");
			}



	}

}