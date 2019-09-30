import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int bug[] = new int[n];
        double bugs = 0.0;
        double sum = 0.0;

        for(int i=0; i<n; i++){
            bug[i] = sc.nextInt();
        }

        for(int i=0; i<n; i++){
            if(bug[i] == 0){
                continue;
            }
            sum += bug[i];
            bugs++;
        }
        double ave = sum/bugs;
        System.out.println((int)Math.ceil(ave));
    }
}