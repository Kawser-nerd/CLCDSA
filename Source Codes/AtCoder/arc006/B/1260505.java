import java.util.*;

public class Main {
	public static void main(String[] args) {
		Amida amida = new Amida();
		amida.startAmida();
		amida.printHitLine();
	}
}

class Amida {
	
	String[][] amida;
	int currentIndex;
	int lineCount;
	int rowCount;
	
	public Amida() {
		Scanner scan = new Scanner(System.in);
		this.lineCount = 2*(scan.nextInt()) - 1;
		this.rowCount = scan.nextInt();
		
		this.amida = new String[rowCount][lineCount];
		//??????????????
		String[] tmpArr = new String[rowCount + 1];
		for (int i = rowCount; i >= 0 ; i--) {
			tmpArr[i] = scan.nextLine();
		}
		
		for (int i = 0; i < rowCount; i++) {
			char[] charArr = tmpArr[i].toCharArray();
			for (int j = 0; j < lineCount; j++) {
				this.amida[i][j] = String.valueOf(charArr[j]);
			}
		}
		
		//?????
		String currentPoint = scan.nextLine();
		char[] currArr = currentPoint.toCharArray();
		for (int i = 0; i < currArr.length; i++) {
			if (currArr[i] == "o".toCharArray()[0]) {
				this.currentIndex = i;
			}
		}
	}

	public void startAmida() {
		for (int i = 0; i < rowCount; i++) {
			if (currentIndex < lineCount - 1 && amida[i][currentIndex + 1].equalsIgnoreCase("-")) {
				currentIndex += 2;
			} else if (currentIndex > 0 && amida[i][currentIndex - 1].equalsIgnoreCase("-")) {
				currentIndex -= 2;
			}
		}		
	}
	
	public void printHitLine() {
		int ans = currentIndex / 2 + 1;
		System.out.println(ans);
	}
	
}