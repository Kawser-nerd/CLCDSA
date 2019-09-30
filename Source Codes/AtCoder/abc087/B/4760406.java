import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        String str1 = null;
        String str2 = null;
        String str3 = null;
        String str4 = null;

        try {
            str1 = br.readLine();
            int cnt500 = Integer.parseInt(str1);

            str2 = br.readLine();
            int cnt100 = Integer.parseInt(str2);

            str3 = br.readLine();
            int cnt50 = Integer.parseInt(str3);

            str4 = br.readLine();
            int cntAll = Integer.parseInt(str4);

            int ptn = 0;

            for (int i = 0 ; i <= cnt500 ; i++) {

                for (int j = 0 ; j <= cnt100 ; j++) {

                    for (int k = 0 ; k <= cnt50 ; k++) {

                    	int money = i*500 + j*100 + k*50;

                    	if (money == cntAll) {
                    		ptn ++;
                    	}

                    }

                }

            }

            br.close();


            System.out.println(ptn);




        } catch (IOException e) {
            e.printStackTrace();
        }


    }

}