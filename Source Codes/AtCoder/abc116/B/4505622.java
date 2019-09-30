import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	sc.close();
    	int ans = 1;
    	if(N == 1 || N == 2 || N == 4){
    		System.out.println(4);
    		System.exit(0);
    	}
    	while(true){
    		if(N % 2 == 0){
    			N = N / 2;
    			ans++;
    		}else{
    			N = N * 3 + 1;
    			ans++;
    		}
    		if(N == 4) break;
    	}
    	System.out.println(ans + 3);
    }
}