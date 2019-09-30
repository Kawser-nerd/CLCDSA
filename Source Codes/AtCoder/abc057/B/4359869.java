import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static int abs(int x){
        return (x > 0)? x : -x;
    }

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        List<Integer> list_a = new ArrayList<Integer>();
        List<Integer> list_b = new ArrayList<Integer>();
        List<Integer> list_c = new ArrayList<Integer>();
        List<Integer> list_d = new ArrayList<Integer>();
        
        for(int i = 0; i < n; i++){
            int p = scan.nextInt();
            int q = scan.nextInt();
            list_a.add(p);
            list_b.add(q);
        }

        for(int i = 0; i < m; i++){
            int p = scan.nextInt();
            int q = scan.nextInt();
            list_c.add(p);
            list_d.add(q);
        }

        for(int i = 0; i < n; i++){
            int minIndex = 0, minDiff = 1234567890;
            for(int j = 0; j < m; j++){
                int diff = abs(list_a.get(i) - list_c.get(j)) + abs(list_b.get(i) - list_d.get(j));

                if(diff < minDiff){
                    minIndex = j + 1;
                    minDiff = diff;
                }
            }
            System.out.println(minIndex);
        }
    }
}