import java.io.*;
import java.util.*;

public class war {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("war.in"));
        
        int a = Integer.parseInt(in.nextLine());
        
        for(int i = 0; i < a; i++) {
            int n = Integer.parseInt(in.nextLine());
            String[] naomi = in.nextLine().split(" ");
            String[] ken = in.nextLine().split(" ");
            ArrayList<Double> kenw = new ArrayList<Double>();
            ArrayList<Double> naomiw = new ArrayList<Double>();
            for(int j = 0; j < n; j++) {
                naomiw.add(Double.parseDouble(naomi[j]));
                kenw.add(Double.parseDouble(ken[j]));
            }
            Collections.sort(naomiw);
            Collections.sort(kenw);
            int badscore = 0;
            ArrayList<Double> naomiw2 = new ArrayList<Double>(naomiw);
            ArrayList<Double> kenw2 = new ArrayList<Double>(kenw);
            for(int j = 0; j < n; j++) {
                double weight1 = naomiw.remove(0);
                double weight2 = 0;
                boolean foundone = false;
                for(int k = 0; !foundone && k < kenw.size(); k++) {
                    if(kenw.get(k) > weight1) {
                        foundone = true;
                        kenw.remove(k);
                    }
                }
                if(!foundone) {
                    badscore++;
                    kenw.remove(0);
                }
            }
            int goodscore = 0;
            boolean dontstop = true;
            while(dontstop && !naomiw2.isEmpty()) {
                boolean rad = true;
                for(int j = 0; j < naomiw2.size(); j++) {
                    if(naomiw2.get(j) < kenw2.get(j)) {
                        rad = false;
                    }
                }
                if(rad) {
                    dontstop = false;
                    goodscore = naomiw2.size();
                } else {
                    naomiw2.remove(0);
                    kenw2.remove(kenw2.size() - 1);
                }
            }
            if(dontstop) goodscore = 0;
            System.out.println("Case #" + (i + 1) + ": "+ goodscore + " " + badscore);
        }
    }
}