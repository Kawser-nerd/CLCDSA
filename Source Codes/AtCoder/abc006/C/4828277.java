import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        boolean check = false;
        for(int z=0; z<=m/4; z++) {
            if(check){
                break;
            }
            int y = m - 2 * n - 2 * z;
            if(y >= 0) {
                int x = n - y - z;
                if (x >= 0) {
                    check = true;
                    System.out.println(x + " " + y + " " + z);
                }
            }

        }

        if(!check) {
            System.out.println("-1 -1 -1");
        }
    }
}