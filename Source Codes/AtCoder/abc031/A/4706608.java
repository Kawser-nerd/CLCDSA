import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int d=sc.nextInt();
        System.out.println(Math.min(a+1, d+1)*Math.max(a,d));
    }
}