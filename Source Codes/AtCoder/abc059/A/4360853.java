import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String s1 = scan.next();
        String s2 = scan.next();
        String s3 = scan.next();
        //int x = 'a'; //large
        //int y = 'A'; //small
        //System.out.println(x);
        //System.out.println(y);

        System.out.print((char)(s1.charAt(0) - ('a' - 'A')));
        System.out.print((char)(s2.charAt(0) - ('a' - 'A')));
        System.out.print((char)(s3.charAt(0) - ('a' - 'A')) + "\n");
    }
}