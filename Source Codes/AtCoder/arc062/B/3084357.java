import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int N = s.length();
        //AtCoDeer should play "Paper" as much as possible
        int score = 0;
        for(int n=0;n<N;n++){
        	int atHand = (n%2==0) ? 0 : 1;
        	int topHand = (s.charAt(n)=='g') ? 0 : 1;
        	score += (atHand-topHand);
        }
        System.out.println(score);
    }
}