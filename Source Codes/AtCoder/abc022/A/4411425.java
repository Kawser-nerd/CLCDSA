import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int s=sc.nextInt();
        int t=sc.nextInt();
        int weight=0;
        int output=0;
        for(int i=0;i<n;i++){
            weight+=sc.nextInt();
            if(weight>=s&&weight<=t){
                output++;
            }
        }
        System.out.println(output);
    }
        

    

}