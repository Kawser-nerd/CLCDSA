import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = 0;

        while(a%b!=0){
            a++;
            c++;
        }
        System.out.println(c);
    }
}