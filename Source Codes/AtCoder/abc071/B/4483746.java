import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        String alphabets = "abcdefghijklmnopqrstuvwxyz";
        String S;
        Scanner sc = new Scanner(System.in);
        S = sc.nextLine(); //"cdefghnoprstuvwxy"; //sc.nextLine();
        absAlpha(alphabets , S);
    }

    private static void absAlpha(String alphabets, String input) {
        TreeSet<Character> inputset = new TreeSet<>();
        boolean found = false;
        for (int i=0; i<alphabets.length(); i++){
            String str = String.valueOf(alphabets.charAt(i));
            if (!input.contains(str)){
                System.out.println(str);
                found = true;
                break;
            }
        }
        if (!found)
            System.out.println("None");
    }
}