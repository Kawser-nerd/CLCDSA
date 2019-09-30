package CodeJam2015;

import java.util.Scanner;

public class D {
	static boolean can(int X, int R, int C) { //can gabriel win?
		if (X >= 7) //make a hole-shaped figure
			return false;
		if (X == 1)
			return true;
		if (((R * C) % X) != 0)
			return false;
		if (X == 2)
			return true; //the area determines this
		//X is 3 or greater => existence of L-shape with side length >= 2
		if (R == 1 || C == 1) return false; //richard chooses L-shape
		if (X == 3) {
			// either [][][] or [][]
			//                    []
			//at least one of R and C is a multiple of 3
			//richard will sure lose if he chooses the long shaped one
			//gabriel can put two L-shaped ones side by side to form a 2 by 3
			//along with long shaped ones, he can make any n by 3
			//and hence any n by 3m
			return true;
		}
		if (X == 4) {
			if (R == 2 || C == 2) return false; //richard chooses T-shape
			  //for either side, there is x to fill in on the long side
			  //and x+1 on the short side
			  // [][][] . . .   <-- 3    = k   \
			  //   [] . . . .   <-- 3+1  = k+1 / 2k+1 not divisible by 4
			// either at least one of R and C is a multiple of 4,
			// or both are even
			// ==> either 3 by 4k, or 4+2k by 4+2l
			// any 3 by 4 can be filled in with any of the 4-ominos
			// so 3 by 4k is doable
			// and 4 by 4 can be made with another long sided one
			// so 4+2k by 4+2l can be done by putting 2 by 2 blocks.
			return true;
		}
		//X is 5 or greater => existence of L-shape with side length >= 3
		if (R <= 2 || C <= 2) return false; //richard chooses L-shape
		if (X == 5) {
			//   1       2        3         4        5       6       7      8
			// [][][] [][][][] [][][][] [][][][][] [][][] [][][]   [][][] [][][]
			// [][]     []     []                  []  []     [][]   []   []
			//                                                       []   []
			//    9     10     11     12
			// [][]   []     []       []  
			//   [][] [][][] [][][] [][][]
			//     []     []   []     []  
			//at least one of R and C is a multiple of 5
			/*if (R == 3 || C == 3) {
				//1 + 14 can
				//2 + 3 + 7 can
				//4 definitely can
				//5 + 6 + 1 can
				//8 + 1 can
				//9 cannot. bottom side needs 3 + 3k size, so is at least 15
				if ((R == 3 && C == 5) || (C == 3 && R == 5)) return false;
				//if other side is at least 10, 9 can
				//10 can => 11 and 12 can
				//otherwise, all 3 by 5 can be done => 3 by 5k can be done by all except 9
				//3 by 5+5k can be done by 9 as well
				//all l by 5k can be done by doing 3 by 5k and then putting in lots of long sides.
				return true;
			}*/
			/*if (R == 4 || C == 4) {
				//1 + 2 can
				//3 + 1 can
				//4 definitely can
				//5 + 1 + 3 can
				//6 + 1 + 3 can
				//7 + 1 + 8 + 3 can
				//9 + 1 + 2 + 3 can
				//10 + 8 + 1 + 3 can
				//11 + 8 + 5 + 3 can
				//12 + 5 + 4 can
				return true;
			}*/
			if ((R == 3 && C == 5) || (C == 3 && R == 5)) return false;
			return true;
		}
		if (X == 6) {
			//   1         
			// [][][][][][]
			//             
			//      2          3          4
			// [][][][][] [][][][][] [][][][][]
			// []           []           []
			//     5        6        7        8         9
			// [][][][]   [][]     []  []   []    []   [][]  
			//       [][] [][][][] [][][][] [][][][] [][][][]
			//     10      11      12        13       14        15
			//  []         []     []       []       []       []
			//  []         []     [][][][] [][][][] [][][][] [][][][]
			//  [][][][] [][][][] []         []         []         []
			//	 16         17     18       19         20       21   
			//   []       []     [][][]   [][][]   [][][]     [][][]  
			// [][][][] [][][][]     [][] []  [][]     [][][]   [][][]
			//     []     []         []           
			//    22       23   24     25        26       27      28 
			//             []
			// [][][]  [][][] [][]     []     [][][]   [][][]   [][][]
			// [][][]    []   [][][] [][][]       []       [][] []    
			//           []   []         [][]     [][]       [] [][]  
			//   29      30     31     32      33   34    35
			// [][][] []  [] [][]     [][][]  [][] [][]   []  
			//   []   [][][]   [][][] [][]  [][][] [][][] [][]
			// [][]     []         [] []      []       []   [][]
			//                                                []
			if (R == 3 || C == 3) return false; //choose shape 13
			if (R == 4 || C == 4) {
				// 4 by 6, 4 by 9, 4 by 12, ..., 4 by 3k
				// if doable for some k, then doable for all l >= k, 4 by 3l
				// exhaustive search shows its doable for all 4 by 6
				return true;
			}
			// since 4 by 6 is doable for all monimos, so n by 6 is doable for all monimos
			// so n by 6k is doable for all monimos
			
			// how about 2k by 6l+3, k not divisible by 3
			// 4 by 6 is doable, so 4 by 9 is doable. tile 2 by 6's until cover
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			int X = sc.nextInt();
			int R = sc.nextInt();
			int C = sc.nextInt();
			
			if (can(X, R, C))
				System.out.println("Case #" + cases + ": GABRIEL");
			else
				System.out.println("Case #" + cases + ": RICHARD");
		}
		sc.close();
	}

}
/*
4
2 2 2
2 1 3
4 4 1
3 2 3
*/