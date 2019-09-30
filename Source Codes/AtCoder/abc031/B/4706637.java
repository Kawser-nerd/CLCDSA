import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l=sc.nextInt();
        int h=sc.nextInt();
        int n=sc.nextInt();
        int tmpA;
        for(int i=0;i<n;i++){
            tmpA=sc.nextInt();
            System.out.println(tmpA>h?-1:(tmpA<l?l-tmpA:0));
        }
    }
}