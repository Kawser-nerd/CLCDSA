import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        long sum = 0;
        int tmp = 2;
        StringBuilder sb = new StringBuilder();
        ArrayList al = new ArrayList<Integer>();

        if(n == 3){
            System.out.println("2 5 63");
            return;
        }
        if(n == 4){
            System.out.println("2 5 20 63");
            return;
        }
        if(n == 5){
            System.out.println("2 5 30 50 63");
            return;
        }

        for(int i=0; i<n; i++){
            while(true){
                if(tmp%2==0 || tmp%3==0){
                    al.add(tmp);
                    
                    sum += tmp;
                    tmp++;
                    break;
                }
                tmp++;  
            }
        }
        
        if(sum % 6 == 0){

        }else if(sum % 6 == 2){
            al.removeAll(Arrays.asList(new Integer[]{8}));
            al.add(30000);
        }else if(sum % 6 == 3){
            al.removeAll(Arrays.asList(new Integer[]{9}));
            al.add(30000);
        }else if(sum % 6 == 5){
            al.removeAll(Arrays.asList(new Integer[]{9}));
            al.add(29998);
        }

        for(int i=0; i<n; i++){
            sb.append(al.get(i));
            sb.append(" ");       
        }
        System.out.println(new String(sb));
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.