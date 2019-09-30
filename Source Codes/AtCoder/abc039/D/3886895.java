import java.util.Scanner;

class Main{
	static int n;
	static long ans = 1000000000;
	static int[] memo;
	static int[] dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int h = sc.nextInt();
		int w = sc.nextInt();
		String[]  strings = new String[h];
		boolean[][] map = new boolean[h][w];

		for(int i = 0;i < h;i++){
			strings[i] = sc.next();
		}
		
		if(h == 1 && w == 1){

			if(strings[0].charAt(0) == '#'){
				System.out.println("possible");
				System.out.println('#');
				return;
			}else{
				System.out.println("possible");
				System.out.println('.');
				return;

			}

		}


		if(h == 1){

			if(strings[0].charAt(0) == '#' && strings[0].charAt(1) == '.'){	
				System.out.println("impossible");
				return;
			}
			for(int i = 1;i < w-2;i++){
				if(strings[0].charAt(i-1) == '#' && strings[0].charAt(i) == '#' && strings[0].charAt(i+1) == '#' ){
					System.out.println("impossible");
					return;
				}
			}
			if(strings[0].charAt(w-2) == '.' && strings[0].charAt(w-1) == '#'){	
				System.out.println("impossible");
				return;
			}

			char[] ans = new char[w];
			for(int i= 1;i < w-1;i++){
				if(strings[0].charAt(i-1) == '#' && strings[0].charAt(i) == '#' && strings[0].charAt(i+1) == '#'){
					ans[i] = '#';
				}else{
					ans[i] = '.';
				}
			}
			if(strings[0].charAt(0) == '#' && strings[0].charAt(1) == '#'){
				ans[0] = '#';
			}else{
				ans[0] = '.';
			}

			if(strings[0].charAt(w-2) == '#' && strings[0].charAt(w-1) == '#'){
				ans[w-1] = '#';
			}else{
				ans[w-1] = '.';
			}

			System.out.println("possible");
			for(int i=0;i < w;i++){
				System.out.print(ans[i]);
			}
			return;

		}
		if(w == 1){

			if(strings[0].charAt(0) == '#' && strings[1].charAt(0) == '.')		{	
				System.out.println("impossible");
				return;
			}
			for(int i = 0;i < h-2;i++){
				if(strings[i].charAt(0) == '#' && strings[i+1].charAt(0) == '#' && strings[i+2].charAt(0) == '#' ){
					System.out.println("impossible");
					return;
				}
			}
			if(strings[h-2].charAt(0) == '.' && strings[h-1].charAt(0) == '#')		{	
				System.out.println("impossible");
				return;
			}


			char[] ans = new char[h];
			for(int i= 1;i < h-1;i++){
				if(strings[i-1].charAt(0) == '#' && strings[i].charAt(0) == '#' && strings[i+1].charAt(0) == '#'){
					ans[i] = '#';
				}else{
					ans[i] = '.';
				}
			}
			if(strings[0].charAt(0) == '#' && strings[1].charAt(0) == '#'){
				ans[0] = '#';
			}else{
				ans[0] = '.';
			}

			if(strings[h-2].charAt(0) == '#' && strings[h-1].charAt(0) == '#'){
				ans[h-1] = '#';
			}else{
				ans[h-1] = '.';
			}
			ans[h] = '&';
			System.out.println("possible");
			for(int i=0;i < h;i++){
				System.out.println(ans[i]);
			}
			return;
		}


		for(int i = 0;i < h;i++){
			for(int j = 0;j < w;j++){

				if(i == 0 && j == 0){				//corner
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j+1) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j+1) == '#' ){
						map[i][j] = true;
						map[i][j+1] = true;
						map[i+1][j] = true;
						map[i+1][j+1] = true;
					}
				}else if(i == h-1 && j == 0){
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j+1) == '#' &&strings[i-1].charAt(j) == '#' && strings[i-1].charAt(j+1) == '#' ){
						map[i][j] = true;
						map[i][j+1] = true;
						map[i-1][j] = true;
						map[i-1][j+1] = true;
					}

				}else if(i == 0 && j == w-1){
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j-1) == '#' ){
						map[i][j] = true;
						map[i][j-1] = true;
						map[i+1][j] = true;
						map[i+1][j-1] = true;
					}

				}else if(i == h-1 && j == w-1){
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i-1].charAt(j) == '#' && strings[i-1].charAt(j-1) == '#' ){
						map[i][j] = true;
						map[i][j-1] = true;
						map[i-1][j] = true;
						map[i-1][j-1] = true;
					}

				}else{
					if(i == 0){				//hen
						if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i].charAt(j+1) == '#' && strings[i+1].charAt(j-1) == '#' && strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j+1) == '#' ){
							map[i][j] = true;
							map[i][j-1] = true;
							map[i][j+1] = true;
							map[i+1][j-1] = true;
							map[i+1][j] = true;
							map[i+1][j+1] = true;
						}
					}else if(j == 0){
						if(strings[i].charAt(j) == '#' && strings[i-1].charAt(j) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j+1) == '#' && strings[i].charAt(j+1) == '#' && strings[i-1].charAt(j+1) == '#' ){
							map[i][j] = true;
							map[i-1][j] = true;
							map[i+1][j] = true;
							map[i+1][j+1] = true;
							map[i][j+1] = true;
							map[i-1][j+1] = true;
						}
					}else if(i == h-1){
						if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i].charAt(j+1) == '#' && strings[i-1].charAt(j+1) == '#' && strings[i-1].charAt(j) == '#' && strings[i-1].charAt(j+1) == '#' ){
							map[i][j] = true;
							map[i][j-1] = true;
							map[i][j+1] = true;
							map[i-1][j-1] = true;
							map[i-1][j] = true;
							map[i-1][j+1] = true;
						}
					}else if(j == w-1){
						if(strings[i].charAt(j) == '#' && strings[i-1].charAt(j) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j-1) == '#' && strings[i].charAt(j-1) == '#' && strings[i+1].charAt(j-1) == '#' ){
							map[i][j] = true;
							map[i+1][j] = true;
							map[i-1][j] = true;
							map[i][j-1] = true;
							map[i+1][j-1] = true;
							map[i-1][j-1] = true;
						}
					}else{
						if(strings[i].charAt(j) == '#' && strings[i-1].charAt(j) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j-1) == '#' && strings[i].charAt(j-1) == '#' && strings[i-1].charAt(j-1) == '#' && strings[i+1].charAt(j+1) == '#' && strings[i].charAt(j+1) == '#' && strings[i-1].charAt(j+1) == '#' ){
							map[i][j] = true;
							map[i][j-1] = true;
							map[i][j+1] = true;
							map[i-1][j] = true;
							map[i-1][j-1] = true;
							map[i-1][j+1] = true;
							map[i+1][j-1] = true;
							map[i+1][j] = true;
							map[i+1][j+1] = true;
						}


					}


				}
			}

		}

		for(int i = 0;i < h;i++){				//judge
			for(int j = 0;j < w;j++){
				if(map[i][j] == false && strings[i].charAt(j) == '#'){
					System.out.println("impossible");
					return;
				}
			}
		}

		map = new boolean[h][w];
		for(int i = 0;i < h;i++){
			for(int j = 0;j < w;j++){

				if(i == 0 && j == 0){				//corner
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j+1) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j+1) == '#' ){
						map[i][j] = true;

					}
				}else if(i == h-1 && j == 0){
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j+1) == '#' &&strings[i-1].charAt(j) == '#' && strings[i-1].charAt(j+1) == '#' ){
						map[i][j] = true;

					}

				}else if(i == 0 && j == w-1){
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j-1) == '#' ){
						map[i][j] = true;

					}

				}else if(i == h-1 && j == w-1){
					if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i-1].charAt(j) == '#' && strings[i-1].charAt(j-1) == '#' ){
						map[i][j] = true;

					}

				}else{
					if(i == 0){				//hen
						if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i].charAt(j+1) == '#' && strings[i+1].charAt(j-1) == '#' && strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j+1) == '#' ){
							map[i][j] = true;

						}
					}else if(j == 0){
						if(strings[i].charAt(j) == '#' && strings[i-1].charAt(j) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j+1) == '#' && strings[i].charAt(j+1) == '#' && strings[i-1].charAt(j+1) == '#' ){
							map[i][j] = true;

						}
					}else if(i == h-1){
						if(strings[i].charAt(j) == '#' && strings[i].charAt(j-1) == '#' &&strings[i].charAt(j+1) == '#' && strings[i-1].charAt(j+1) == '#' && strings[i-1].charAt(j) == '#' && strings[i-1].charAt(j+1) == '#' ){
							map[i][j] = true;

						}
					}else if(j == w-1){
						if(strings[i].charAt(j) == '#' && strings[i-1].charAt(j) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j-1) == '#' && strings[i].charAt(j-1) == '#' && strings[i+1].charAt(j-1) == '#' ){
							map[i][j] = true;

						}
					}else{
						if(strings[i].charAt(j) == '#' && strings[i-1].charAt(j) == '#' &&strings[i+1].charAt(j) == '#' && strings[i+1].charAt(j-1) == '#' && strings[i].charAt(j-1) == '#' && strings[i-1].charAt(j-1) == '#' && strings[i+1].charAt(j+1) == '#' && strings[i].charAt(j+1) == '#' && strings[i-1].charAt(j+1) == '#' ){
							map[i][j] = true;

						}


					}


				}
			}

		}


		char[][] ans = new char[h][w];

		for(int i = 0;i < h;i++){				//make ans
			for(int j = 0;j < w;j++){
				if(map[i][j] == false){
					ans[i][j] ='.'; 
				}else{
					ans[i][j] = '#';
				}
			}
		}

		System.out.println("possible");
		for(int i = 0;i < h;i++){				//display
			System.out.println(ans[i]);
		}






	}




}

class Pair implements Comparable{
	int from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}