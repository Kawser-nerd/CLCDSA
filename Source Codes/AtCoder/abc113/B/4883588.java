import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
    	try(Scanner sc = new Scanner(System.in)) {

    		int N = sc.nextInt();
    		double T = sc.nextDouble();
    		double A = sc.nextDouble();
    		int town = 1;
    		double min = 10000000;
    		for(int i=1; i<=N; i++) {
    			double h = sc.nextDouble();
    			h = T - h*0.006;
    			if(min > Math.abs(A - h)) {
    				town = i;
    				min = Math.abs(A - h);
    			}
    		}
    		System.out.println(town);

    	}
    }
}