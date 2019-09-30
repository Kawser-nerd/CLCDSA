import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	String X = sc.next();
    	String Y = sc.next();
    	sc.close();
    	if(X.equals(Y)){
    		System.out.println("=");
    	}else if(X.compareTo(Y) < 0){
    		System.out.println("<");
    	}else{
    		System.out.println(">");
    	}
    }
}