import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int no = sc.nextInt();
        //System.out.println("str:"+str.length());
        String[] suki = new String[5];
        for (int i = 0; i < str.length(); i++) {
            suki[i] = str.substring(i, i + 1);
        }
        //System.out.println("suki before");
        for (int i = 0; i < 5; i++) {

            //System.out.println(suki[i]);
        }
        Arrays.sort(suki);
        //System.out.println("suki after");
        for (int i = 0; i < 5; i++) {

            //System.out.println(suki[i]);
        }
        String[] suki2 = new String[25];
        int k = 0,j=0,i=0;
        while(i<25){
            
            //System.out.println("k: "+k+"j: "+j);
            for (j = 0; j < 5; j++) {
                
                suki2[i] = suki[k] + suki[j];
               // System.out.println(suki2[i]);
                i++;
            }
            if (k >= 4) {
                k = 0;
            } else {
                k++;
            }
            j = 0;
        }

//        for ( i = 0; i < 25; i++) {
//            System.out.println("????????????");
//            System.out.println(suki2[i]);
//        }
     System.out.println(suki2[no-1]);
    }
        

}