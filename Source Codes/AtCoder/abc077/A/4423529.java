import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	char[] c1 = sc.next().toCharArray();
    	char[] c2 = sc.next().toCharArray();
    	sc.close();
    	boolean ans = false;
    	if(c1[0] == c2[2] && c1[1] == c2[1] && c1[2] == c2[0]) ans = true;
    	System.out.println(ans ? "YES" : "NO");
    }
}