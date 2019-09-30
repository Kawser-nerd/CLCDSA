import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        //when the game ends, the string must be "abab..."
        //the first letter and last letter cannot be changed
        
        boolean startStringIsOdd = (s.length()%2!=0);
        boolean endStringIsOdd = (s.charAt(0)==s.charAt(s.length()-1));
        System.out.println(startStringIsOdd^endStringIsOdd ? "First" : "Second");
    }
}