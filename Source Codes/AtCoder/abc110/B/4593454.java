import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        Integer empireA[] = new Integer[n];
        Integer empireB[] = new Integer[m];
        for(int i=0; i<n; i++){
            empireA[i] = sc.nextInt();
        }
        Arrays.sort(empireA, Collections.reverseOrder());
        for(int i=0; i<m; i++){
            empireB[i] = sc.nextInt();
        }
        Arrays.sort(empireB);
        for(int z=x+1; z<=y; z++){
            if(empireA[0] < z && empireB[0] >= z){
                System.out.println("No War");
                break;
            }
            if(z == y) System.out.println("War");
        }
    }
}