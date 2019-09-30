import java.util.*;

public class Main {
    private static int n;
    private static String[] x;
    private static int count = 0;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
        x = new String[n];

        for (int i=0;i<n;i++){
            x[i] = scan.next();
        }
    }

    public static void main(String args[]) {
        //??
        input();

        for (int i=0;i<n;i++){
            if (x[i].contains("x")){
                int j=0;
                while (x[i].indexOf('x', j) != -1){
                    j = x[i].indexOf('x', j) + 1;
                    count++;
                }
            }
        }

        boolean flag = true;
        for (int i=0;i<9;i++){
            for (int j=0;j<n;j++){
                if(x[j].charAt(i) == 'o'){
                    if(flag){
                        count++;
                        flag = false;
                    }
                }else flag = true;
            }
            flag = true;
        }

        System.out.println(count);
    }
}