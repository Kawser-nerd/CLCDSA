import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		char[] c = sc.next().toCharArray();
		for(int i=0; i<(1<<3); i++){
			StringBuffer str = new StringBuffer();
			str.append(c[0]);
			int cal = Character.getNumericValue(c[0]);
			for(int j=0; j<3;j++){
				if ((1 & i>>j) == 1){
					str.append("+");
					cal += Character.getNumericValue(c[j+1]);
				}else{
					str.append("-");
					cal -= Character.getNumericValue(c[j+1]);
				}
				str.append(c[j+1]);
			}
			if(cal == 7){
				System.out.println(str.toString() + "=7");
				break;
			}
		}

		sc.close();
	}


}