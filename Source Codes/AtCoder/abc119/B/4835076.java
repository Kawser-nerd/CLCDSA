import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
        double money;
        String unit;
        double sum = 0;
        for(int i=0; i<num; i++){
			money = sc.nextDouble();
     		unit = sc.next();
            if(unit.equals("BTC")) money = money * 380000.0;
            sum += money;
        }
        
		System.out.println(sum);
	}
}