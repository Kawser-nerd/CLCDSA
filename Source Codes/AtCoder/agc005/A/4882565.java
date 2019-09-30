import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] x = sc.next().toCharArray();
        int sCnt = 0;
        int setCnt = 0;
        for (int i = 0; i < x.length; i++) {
            if(x[i] == 'S') sCnt++;
            else if(sCnt>0){
                setCnt++;
                sCnt--;
            }
        }
        System.out.println(x.length - (setCnt * 2));
        sc.close();

    }

}