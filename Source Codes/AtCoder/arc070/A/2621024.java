import java.util.Scanner;




public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {
    	Scanner sc=new Scanner(System.in);

    	int X=sc.nextInt();

    	for(int i=1;i<=X;i++) {

    		int max=i*(i+1)/2;

    		if(X<=max) {
    			System.out.println(i);
    			return;
    		}

    	}

    }


}