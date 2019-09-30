import java.util.*;

public class Main{
	
	public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int N = sc.nextInt();
        String all = sc.next();

        String past, crr;
        int def = 0;
        int cost = 0;
        int min_cost = 0;

        crr = String.valueOf(all.charAt(0));
        for(int i=1; i<N; i++){
            past = crr;
            crr = String.valueOf(all.charAt(i));

            if(past.equals("W")) cost++;
            
            if(crr.equals("E")){
                cost--;
                def++;
            }

            if(cost < min_cost) min_cost = cost;

        }

        System.out.println(def + min_cost);
        
	}

}