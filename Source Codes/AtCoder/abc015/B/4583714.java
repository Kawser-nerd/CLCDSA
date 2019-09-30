import java.util.ArrayList;
import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int sum = 0;
			ArrayList<Integer>list = new ArrayList<Integer>();

			int num = sc.nextInt();


			for(int n=0; n<num; n++) {
				int bu = sc.nextInt();
				if(bu!=0) {
					list.add(bu);
					sum = sum + bu;
				}
			}

			float a = (sum+(list.size()-1))/list.size();
			int answer =  (int)(Math.ceil(a));

			System.out.println(answer);
		}
}