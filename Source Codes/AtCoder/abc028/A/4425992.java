import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        if(N<=59) System.out.println("Bad");
        else if(N<=89) System.out.println("Good");
        else if(N<=99) System.out.println("Great");
        else System.out.println("Perfect");
    }
}