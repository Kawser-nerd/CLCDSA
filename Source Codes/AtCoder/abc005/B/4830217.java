import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){
//		String [][] boad = new String[4][4];
		
		int x1 = Integer.parseInt(sc.next());
		ArrayList<Integer> aaa = new ArrayList<Integer>();
		String answer = null;
		
		for(int h = 0;h < x1;h++){
			aaa.add(Integer.parseInt(sc.next()));
		}
			
		Collections.sort(aaa);
		
	System.out.println(aaa.get(0));
	System.out.flush();
//		BigDecimal xx1 = new BigDecimal(Integer.parseInt(sc.next()));
//		double c = 0;
//		System.out.println();
//		System.out.flush();
		sc.close();
	}
}