import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String [] sArray = s.split("");
		int len = sArray.length;
		boolean judge = true;
		int Ccount = 0;
		if(sArray[0].equals("A"));//1????”A”??
		else judge = false;
		if(sArray[1].equals(sArray[1].toUpperCase())) judge = false;//?????(??)??
		for(int i = 2; i <= len - 2; i++) {//3????????2?????
			if(sArray[i].equals("C")) Ccount++;//”C”????
			else if(sArray[i] == sArray[i].toUpperCase()) judge = false;//(??)??
		}
		if(Ccount != 1) judge = false;//”C”????
		if(sArray[len - 1].equals(sArray[len - 1].toUpperCase())) judge = false;//?????(??)??
		
		if(judge) System.out.println("AC");//????
		else System.out.println("WA");
		
		sc.close();
	}
}