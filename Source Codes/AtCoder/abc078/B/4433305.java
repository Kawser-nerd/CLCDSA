import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	int X = sc.nextInt();
    	int Y = sc.nextInt();
    	int Z = sc.nextInt();
    	sc.close();
    	X = X - Z;
    	int ans = 0;
    	while(X >= 0){
    		X = X - (Y + Z);
    		ans++;
    	}
    	System.out.println(ans == 0 ? 0 : ans-1);
    }
}