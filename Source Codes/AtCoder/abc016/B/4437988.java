import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        if(a+b == c){
            if(a-b == c){
                System.out.println("?");
                System.exit(0);
            }
            System.out.println("+");
        }else if(a-b == c){
            System.out.println("-");
        }else System.out.println("!");
    }
}