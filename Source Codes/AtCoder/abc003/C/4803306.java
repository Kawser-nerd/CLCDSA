import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		ArrayList <Double> list = new ArrayList<Double>();
		
		double trate = 0;
		
		for(int c = 0;c < a;c++){
			if(sc.hasNextInt()){
				list.add(Double.parseDouble(sc.next()));
			}
		}
		if(a != b){
			Collections.sort(list);
			for(int r = a-b;r < a;r++){
				trate = (trate + list.get(r))/2;
			}
		}else{
			Collections.sort(list);
			for(int r = 0;r < b;r++){
				trate = (trate + list.get(r))/2;
			}
		}
		new DecimalFormat("0.000000").format(trate);
		BigDecimal bd_trate = new BigDecimal(trate);
		bd_trate.setScale(6, RoundingMode.HALF_UP);
		
		System.out.println(bd_trate);
		sc.close();
	}
}