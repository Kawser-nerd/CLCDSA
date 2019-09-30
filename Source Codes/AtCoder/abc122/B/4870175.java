import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		String str=sc.next();

		String[] strArray=str.split("");

		int count=0;
		int max=0;

		for(int i=0;i<strArray.length;i++) {

			if( !(strArray[i].equals("A")||strArray[i].equals("C")||strArray[i].equals("G")||strArray[i].equals("T"))) continue;

			count++;


			if(i!=strArray.length-1) {
				for(int j=i+1;j<strArray.length;j++) {

					if( !(strArray[j].equals("A")||strArray[j].equals("C")||strArray[j].equals("G")||strArray[j].equals("T"))) break;

					count++;
				}

			}

			if(max<count) max=count;

			count=0;

		}

		System.out.println(max);

		sc.close();

	}

}