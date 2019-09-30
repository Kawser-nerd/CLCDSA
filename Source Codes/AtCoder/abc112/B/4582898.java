import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int minCost = 1001;
        for(int i=0; i<n; i++){
            int cost = sc.nextInt();
            int time = sc.nextInt();
            if(t >= time){
                if(minCost > cost) minCost = cost;
            }
        }
        if(minCost == 1001) System.out.println("TLE");
        else System.out.println(minCost);
    }
}