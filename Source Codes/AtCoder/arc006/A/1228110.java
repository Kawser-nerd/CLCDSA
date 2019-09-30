import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int b,c[]=new int[6];

		ArrayList<Integer> a=new ArrayList<>();

		boolean bonus=false;
		int count=0;

		for(int i=0;i<6;i++)
			a.add(s.nextInt());
		b=s.nextInt();
		for(int i=0;i<6;i++)
			c[i]=s.nextInt();

		for(int i=0;i<6;i++) {
			if(a.remove(Integer.valueOf(c[i])))
				count++;
			else
				bonus|=c[i]==b;
		}

		int res=0;
		switch (count) {
		case 3:
		case 4:
			res=8-count;
			break;
		case 5:
			res=bonus?2:3;
			break;
		case 6:
			res=1;
			break;
		}
		System.out.println(res);
	}
}