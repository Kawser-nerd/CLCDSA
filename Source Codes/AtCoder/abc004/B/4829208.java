import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){
		String [][] boad = new String[4][4];
//		int x1 = Integer.parseInt(sc.next());
		String answer = null;

		for(int h = 0;h < 4;h++){
				for(int i = 0;i < 4;i++){
					boad[h][i] = sc.next();
			}
		}
		for(int h = 3;h >= 0;h--){
			StringBuilder buff = new StringBuilder();
			for(int i = 3;i >= 0;i--){
				buff.append(boad[h][i]);
				if((h == 0 && i == 0) || i == 0){
				}else{
					buff.append(" ");
				}
			}
			answer = buff.toString();
			System.out.println(answer);
			System.out.flush();
			answer = null;
		}
		
//		BigDecimal xx1 = new BigDecimal(Integer.parseInt(sc.next()));
//		double c = 0;
//		System.out.println();
//		System.out.flush();
		sc.close();
	}
}