import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String o = scan.next();
        String e = scan.next();
        for(int i = 0; i < o.length() + e.length(); i++){
            char c = (i % 2 == 0)? o.charAt(i / 2) : e.charAt((i - 1) / 2);
            System.out.print(c);
        }
        System.out.println();
    }
}