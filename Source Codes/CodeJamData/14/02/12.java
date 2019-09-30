import java.util.*;

public class CookieClicker {
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			double c = reader.nextDouble();
			double f = reader.nextDouble();
			double x = reader.nextDouble();
			
			int low = 0;
			int high = (int)1e7;
			while(low+1000 < high){
				int leftThird = (2*low + high)/3;
				int rightThird = (low + 2*high)/3;
				double fLeft = f(c,f,x,leftThird);
				double fRight = f(c,f,x,rightThird);
				if(fLeft < fRight){
					high = rightThird;
				}else{
					low = leftThird;
				}
			}
			
			double min = 1e18;
			int took = -1;
			for(int i = low; i <= high; i++){
				double chk = f(c,f,x,i);
				if(chk < min)
					took = i;
				min = Math.min(min,chk);
			}
			
			if(took == (int)1e7){
				System.err.println("WARNING");
				System.exit(0);
			}
			
			System.out.printf("Case #%d: %.7f\n",t,min);
		}
	}

	public static double f(double c, double f, double x, int cnt){
		double time = 0;
		double rate = 2;
		double cookies = 0;
		for(int j = 0; j < cnt; j++){
			time += Math.max(0,(c - cookies)/rate);
			cookies += Math.max(0,(c - cookies)) - c;
			rate += f;
		}
		time += Math.max(0,(x - cookies) / rate);
		return time;
	}
}