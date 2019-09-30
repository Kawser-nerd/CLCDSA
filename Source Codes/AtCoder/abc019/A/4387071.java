import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        if((a>=c&&a<=b)||(a<=c&&a>=b)){
            System.out.println(a);
        }else if((b>=a&&b<=c)||(b<=a&&b>=c)){
            System.out.println(b);
        }else{
            System.out.println(c);
        }
    }

}