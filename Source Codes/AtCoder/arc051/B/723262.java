import java.util.Scanner;

public class Main {
    static int N = 10;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();

        int l = 1, r = 1;
        for(int i = 1; i < k; i++) {
            int n = r;
            r += l;
            l = n;
        }
        System.out.println(l + " " + r);
   }
}