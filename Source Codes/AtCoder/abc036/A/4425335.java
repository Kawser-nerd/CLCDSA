import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        if(B%A==0) {
            System.out.println(B/A);
        }else {
            System.out.println(B/A+1);
        }
    }
}