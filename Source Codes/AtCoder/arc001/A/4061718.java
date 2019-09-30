import java.util.*;

import static java.lang.Integer.parseInt;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        int question = sc.nextInt();
//        System.out.println(question);
        ArrayList<String> answers = new ArrayList<String>();
//        ArrayList<Integer> scores = new ArrayList<Integer>();
        int scores[] = new int[4];
        answers.add(sc.next());
//        System.out.println(answers);
//        System.out.println(answers.get(0));
//        System.out.println(scores);
        for(int i=0 ; i<4 ; i++){
            for(int digit=0 ; digit<question ; digit++)
                if (parseInt(answers.get(0).substring(digit, digit+1)) == (i + 1)) {
                    scores[i] = scores[i] + 1;
                }
//            System.out.println(scores[i]);
        }
        int max = scores[0];
        int min = scores[1];
        for (int i = 0; i < scores.length; i++) {
            int v = scores[i];
            if (v > max) {
                max = v;
            }
            if (v < min) {
                min = v;
            }
        }
        System.out.println(max+" "+min);
    }
}