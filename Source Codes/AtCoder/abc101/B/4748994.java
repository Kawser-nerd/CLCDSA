import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());

        int x = n;


        int num = 0;
        while(x > 0){
            num += x % 10;
            x /= 10;
        }
        
        if(n % num == 0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

        sc.close();
    }
}