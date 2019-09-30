import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;
 
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        String S =scanner.next();
        //int [] = new int[N];
        
        System.out.println(S.replace(",", " "));

        scanner.close();
    }
}