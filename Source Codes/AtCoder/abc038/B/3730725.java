import java.util.*;
import static java.lang.System.in;
import static java.lang.System.out;

public class Main{
    public static void main(String[] args){
	Scanner sc=new Scanner(in);
	String[] input1=sc.nextLine().split(" ",0);
	String[] input2=sc.nextLine().split(" ",0);
	int[] hw1=new int[2];
	int[] hw2=new int[2];
	for(int i=0;i<2;i++){
	    hw1[i]=Integer.parseInt(input1[i]);
	    hw2[i]=Integer.parseInt(input2[i]);
	}
	for(int i=0;i<2;i++)
	    for(int j=0;j<2;j++){
		if(hw1[i]==hw2[j]){out.println("YES");return;}
	    }
	out.println("NO");
    }
}