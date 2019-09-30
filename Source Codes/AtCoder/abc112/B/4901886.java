import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
    	try(Scanner sc = new Scanner(System.in)) {

    		int N = sc.nextInt();
    		int T = sc.nextInt();
    		int min = 10000000;
    		while(N-->0) {
    			int c = sc.nextInt();
    			int t = sc.nextInt();
    			if(t<=T && c<min) {
    				min = c;
    			}
    		}
    		System.out.println(min==10000000? "TLE" : min);

    	}
    }
}