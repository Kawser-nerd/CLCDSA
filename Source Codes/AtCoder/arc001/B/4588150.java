import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// get number of problems
		int num = sc.nextInt();
		// get answer
        String ans = sc.next();
		String[] a = ans.split("");

        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;

        //count each
        for(String val: a){
            switch(Integer.parseInt(val)){
                case 1:
                    count1++;
                    break;
                case 2:
                    count2++;
                    break;
                case 3:
                    count3++;
                    break;
                case 4:
                    count4++;
                    break;
            }
        }

        int max = 0;
        int min = 0;

        if(count1>count2){
            max = count1;
            min = count2;
        } else {
            max = count2;
            min = count1;
        }
        if(count3>count4){
            if(count3>max){
                max = count3;
            }
            if(min>count4){
                min = count4;
            }
        } else {
            if(count4>max){
                max = count4;
            }
            if(min>count3){
                min = count3;
            }
        }
		// output
		System.out.println(max + " " + min);
	}
}