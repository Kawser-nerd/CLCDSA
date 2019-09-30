import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

		double a = Integer.parseInt(sc.next());
		a = a/1000;
		
		double vv = 0;
		
		if(a < 0.1){
			
		}else if(0.1 <= a && a <= 5){
			vv = a * 10;
		}else if(6 <= a && a <= 30){
			vv = a + 50;
		}else if(35 <= a && a <= 70){
			vv = (a-30)/5+80;
		}else{
			vv = 89;
		}
		int intvv = (int) vv;
		System.out.println(String.format("%02d", intvv));
		System.out.flush();
		sc.close();
	}
}