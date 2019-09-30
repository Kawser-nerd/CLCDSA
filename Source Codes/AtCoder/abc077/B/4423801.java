import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	double N = sc.nextDouble();
    	sc.close();
    	for(double i = N; i >= 0; i--){
    		if(Math.sqrt(i) % 1 == 0){
    			System.out.println((int)i);
    			break;
    		}
    	}
    }
}