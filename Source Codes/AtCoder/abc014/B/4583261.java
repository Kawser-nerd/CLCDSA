import java.util.ArrayList;
import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			 ArrayList<Long>mo = new ArrayList<Long>();
			 long answer = 0;
			Scanner sc = new Scanner(System.in);
			//????
			int num = sc.nextInt();
			int du = sc.nextInt();

		  //?????
		  String d =Integer.toBinaryString(du);

		  for(int i=0;i!=d.length();i++) {
				  	int c=sc.nextInt();
				  	if(d.charAt(d.length()-1-i)=='1') {
				  		answer+=c;
				  		}
				  	}
				  System.out.println(+answer);
				  }
				  
		}