import java.util.*;
import java.io.*;

public class Main {
    public static String reverse(String s){
        if(s.equals("")) return "";
        else return reverse(s.substring(1))+s.charAt(0);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] dictionary = new String[N];
        for(int n=0;n<N;n++){
        	dictionary[n] = reverse(sc.next());
        }
        Arrays.sort(dictionary);
        for(int n=0;n<N;n++){
        	System.out.println(reverse(dictionary[n]));
        }
    }
}