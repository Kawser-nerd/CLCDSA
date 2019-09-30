import java.util.*;

public class Main{
	
	public static void main (String[] args) {
		
		Main main = new Main();
		
		main.masume();
		
	}
	
	private void masume() {
		Scanner scanner = new Scanner (System.in);
		
		int height = scanner.nextInt();
		int width = scanner.nextInt();
		String [][] list = new String[height][width];
		
		scanner.nextLine();
		for (int tate=0; tate<height; tate++) {
			String temp =scanner.nextLine();
			String[] tempList = temp.split("");
			for (int yoko=0; yoko<width; yoko++) {
				list[tate][yoko]=tempList[yoko];
			}
		}
		
		for (int tate=0; tate<height; tate++) {
			list=hanteiYoko(list, tate, height, width);
		}
		
		for (int yoko=0; yoko<width; yoko++) {
			list=hanteiTate(list, yoko, height, width);
		}
		
		for (int tate=0; tate<height; tate++) {
			boolean nullFlag =true;
			for (int yoko=0; yoko<width; yoko++) {
				if (list[tate][yoko]=="null") {
				} else {
					System.out.print(list[tate][yoko]);
					nullFlag=false;
				}
			}
			if(nullFlag!=true) {
			System.out.println();
			}
		}
	}
	
	private String[][] hanteiYoko (String[][]list, int tate,int height, int width) {
		boolean hantei=true;
		
		for (int yoko=0; yoko<width; yoko++) {
			if (list[tate][yoko].equals(".")) {
			} else {
				hantei=false;
			}
		}
		if (hantei==true) {
			for (int yoko=0; yoko<width; yoko++) {
				list[tate][yoko]="null";
			}
		}
		
		
		return list;
	}
	
	private String[][] hanteiTate(String[][]list, int yoko, int height, int width) {
		boolean hantei=true;
		
		for (int tate=0; tate<height; tate++) {
			if (list[tate][yoko].equals(".")||list[tate][yoko].equals("null")) {
		} else {
			hantei=false;
		}
		}
		if (hantei==true) {
			for (int tate=0; tate<height; tate++) {
				list[tate][yoko]="null";
			}
		}
		
		return list;
	}
}