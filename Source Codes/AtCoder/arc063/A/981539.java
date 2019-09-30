import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		String string = input.nextLine();
		char first = ' ';
		int counter = 0;
		for(char b : string.toCharArray()){
			if(first == ' '){
				first = b;
			}  else{
				if(b == first){
					
				} else {
					first = b;
					counter++;
				}
			}
		}
		System.out.println(counter);
	}

}