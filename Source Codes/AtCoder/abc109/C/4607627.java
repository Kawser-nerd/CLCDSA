import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer points[] = new Integer[n+1];
        for(int i=0; i<n+1; i++){
            points[i] = sc.nextInt();
        }
        Arrays.sort(points, Collections.reverseOrder());
        int intervals[] = new int[n];
        for(int i=1; i<n+1; i++){
            intervals[i-1] = points[i-1] - points[i];
        }
        int ans = gcd(intervals);
        System.out.println(ans);
    }

    public static int gcd(int a, int b){
        if(a < b){
            int swap = a;
            a = b;
            b = swap;
        }
        int r;
        while((r = a % b) != 0){
            a = b;
            b = r;
        }
        return b;
    }

    public static int gcd(int array[]){
        int g = array[0];
        for(int value : array){
            g = gcd(g, value);
        }
        return g;
    }
}