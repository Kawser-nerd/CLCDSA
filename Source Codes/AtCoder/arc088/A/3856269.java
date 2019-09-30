import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long X = sc.nextLong();
        long Y = sc.nextLong();
        int ans = 0;
        while(X<=Y){
            X *= 2;
            ans++;
        }
        System.out.println(ans);

    }
}