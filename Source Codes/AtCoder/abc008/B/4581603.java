import java.util.ArrayList;
import java.util.Scanner;


public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int n = sc.nextInt();

			ArrayList<String>list = new ArrayList<String>();

			for(int l=0; l<n;l++) {
				String b = sc.next();
				list.add(b);
			}

			int max = 0;
			String ans = "";
			int count = 0;

			for(int i =0; i<n; i++) {
				String com = list.get(i);
				for(String s: list) {
					if(s.equals(com)) {
						count++;
					}
					if(count > max) {
						max = count;
						ans = s;
					}
				}
				count = 0;
			}
			System.out.println(ans);
}
}