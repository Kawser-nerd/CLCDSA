import java.util.*;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Deque;


public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        
        long sum = 0;
        for (int i = 0; i < (1<<s.length()-1); i++) {
            String shiki = s.substring(0, 1);
            for (int j = 0; j < s.length()-1; j++) {
                if ((1 & (i>>j)) == 1) {
                    //shiki += "+" + s.substring(j+1, j+2);
                    sum += Long.parseLong(shiki);
                    shiki = s.substring(j+1, j+2);
                }
                else {
                    shiki += s.substring(j+1, j+2);
                }
            }
            sum += Long.parseLong(shiki);
        }
        
        System.out.println(sum);
        
    }
}