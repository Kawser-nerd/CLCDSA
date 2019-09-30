import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char c[] = s.toCharArray();

        int ans = 700;
        for(int i = 0; i < c.length; i++){
            if(c[i] == 'o'){
                ans += 100;
            }
        }
        

        System.out.println(ans);

        sc.close();
    }
}