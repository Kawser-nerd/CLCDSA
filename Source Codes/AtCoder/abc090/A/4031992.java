import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	String[] ary = new String[3];
    	for(int i = 0; i < 3; i++){
    		ary[i] = sc.next();
		}

    	System.out.println(ary[0].substring(0, 1) + ary[1].substring(1, 2) + ary[2].substring(2, 3));
    }

}