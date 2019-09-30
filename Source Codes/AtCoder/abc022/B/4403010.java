import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        //List<Integer> list = new ArrayList<Integer>();
        int [] numArray = new int [100000 + 1];
        int ans = 0;
        for(int i = 0; i < n; i++){
            int a = sc.nextInt();
            numArray[a]++;

            if(numArray[a] >= 2){
                ans++;
            }
            /*if(list.contains(a)){
                ans++;
            }
            
            list.add(a);*/
        }

        System.out.println(ans);
    }    
}