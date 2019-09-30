import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int t = sc.nextInt();

        int temp = s;
        s = t;
        t = temp;

        System.out.println(s + " " + t);
    }
}