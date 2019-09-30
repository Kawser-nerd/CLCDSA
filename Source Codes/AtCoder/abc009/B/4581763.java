import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;


public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int num = sc.nextInt();

			ArrayList<Long>list= new ArrayList<Long>();

			for(int i = 0; i<num; i++) {
				long n = sc.nextLong();
				list.add(n);
			}
			
			Long i = Collections.max(list);
			ArrayList<Long>c= new ArrayList<Long>();
			Collections.addAll(c, i);
			
			list.removeAll(c);
			
			Long a = Collections.max(list);
			System.out.println(a);


		}
}