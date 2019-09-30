import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	int R = sc.nextInt();
    	int G = sc.nextInt();
    	sc.close();
    	System.out.println(2 * G - R);
    }
}