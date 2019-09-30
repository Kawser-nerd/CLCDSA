import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());

        int cnt = 0;

        for(int i = a; i <= b; i++){
            String s = String.valueOf(i);
            char[] c = s.toCharArray();
            if(c[0] == c[4] && c[1] == c[3]){
                cnt ++;
            }
        }

        System.out.println(cnt);
        
    }
}