import java.util.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();

        String ans = (a + b > c + d)? "Left" : (a + b == c + d)? "Balanced" : "Right";
        System.out.println(ans);
    }
}