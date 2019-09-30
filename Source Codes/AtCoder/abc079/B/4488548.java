import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	sc.close();
    	long ans = 1;
    	long L1 = 2;
    	long L2 = 1;
    	for(int i = 1; i < N; i++){
    		ans = L1 + L2;
    		L1 = L2;
    		L2 = ans;
    	}
    	System.out.println(ans);
    }
}