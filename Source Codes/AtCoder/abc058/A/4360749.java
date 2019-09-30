import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        String ans = (b - a == c - b)? "YES" : "NO";
        System.out.println(ans);
    }
}