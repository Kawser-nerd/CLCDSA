import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        String[] chars={"a","b","c"};
        for(int i=0;i<Math.pow(3, n);i++){
            for(int j=n;j>0;j--){
                System.out.print(chars[(i%(int)Math.pow(3,j)-i%(int)Math.pow(3, j-1))/(int)Math.pow(3, j-1)]);
            }
            System.out.println();
        }
    }
}