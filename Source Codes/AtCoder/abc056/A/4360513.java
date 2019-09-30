import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String a_str = scan.next();
        String b_str = scan.next();
        char a = a_str.charAt(0);
        char b = b_str.charAt(0);
        char ans;

        if(a == 'H'){
            ans = (b == 'H')? 'H' : 'D';
        }else{
            ans = (b == 'D')? 'H' : 'D';
        }
        System.out.println(ans);
    }
}