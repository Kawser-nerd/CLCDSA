import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        boolean aFound = false;
        boolean bFound = false;
        boolean cFound = false;
        for( int i = 0 ; i<3 ;i++) {
            if(input.charAt(i) == 'a') {
                aFound =true;
            }
            else if(input.charAt(i)=='b') {
                bFound = true;
            }
            else {
                cFound =true;
            }
        }
        if(aFound && bFound && cFound) {
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        }
    }
}