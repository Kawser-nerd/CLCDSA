import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();

        int num = Integer.parseInt(a + b);

        int s = (int)Math.sqrt(num);

        if(s * s == num){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}