import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        long k = Long.parseLong(sc.next());

        char c[] = s.toCharArray();

        char cs = '1';

        for(int i = 0; i < k; i++){
            if(c[i] != '1'){
                cs = c[i];
                break;
            }
        }

        System.out.println(cs);

        sc.close();
    }
}