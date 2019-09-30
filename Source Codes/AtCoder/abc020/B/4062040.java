import java.util.Scanner;
    public class Main{
    	public static void main(String[] args){
    		Scanner sc = new Scanner(System.in);
    		double A = sc.nextInt();
    		double B = sc.nextInt();
    		double b = B;
    		int count = 0;
    		
    		
    		for(int i = 0; i < 4; i++){
    		    double c = B%10;
    		    B = B/10;
    		    if(c == 0){
    		        count++;
        		    }
    		    else if(c >= 1){
    		       count++;
    		    }else {
    		        break;
    		    }
    		}
    		
    	    double a =Math.pow(10,count);
    	    double ans = a*A+b;
    	    System.out.println(String.format("%.0f", ans*2));
    	}
    }