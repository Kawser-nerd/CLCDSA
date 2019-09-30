import java.util.*;

public class Main {
    public static void main(String[]$) {
        Scanner s=new Scanner(System.in);
        long a=s.nextInt(),b=s.nextInt(),k=s.nextInt(),l=s.nextInt();
        System.out.println(k/l*b+Math.min(k%l*a,b));
    }
}