import java.util.*;


public class Main {
    public static void main(String[] args) {
        // ?????????
        // Let's ???????

        Scanner sc = new Scanner(System.in);
        String[] line = sc.nextLine().split(" ");
        
        int A = Integer.parseInt(line[0]);
        int B = Integer.parseInt(line[1]);
        int C = Integer.parseInt(line[2]);
        
        int[] array = new int[B+1];

        boolean solved = false;
        int l =1;

        while(!solved){

            int newA = A * l;

            int amari = newA % B;
          	if(amari == C){
                solved = true;
                break;
            }

            if(array[amari] == 1){
                break;
            }

            array[amari] = 1;

            l++;
        }

        if(solved){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
       
}