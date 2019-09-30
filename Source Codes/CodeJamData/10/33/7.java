/**
 * @(#)Chessboards.java
 *
 *
 * @author 
 * @version 1.00 2010/5/23
 */

import java.io.*;
import java.util.Scanner;
import java.lang.Math;

public class Chessboards {

		public Cell[][] board;

    public Chessboards(Cell[][] board) {
    	this.board = board;
    }
    
    public void showBoard()
    {
    	for(int i = 0; i < board.length; i++)
    	{
    		for(int j = 0; j < board[0].length; j++)
    		{
    			System.out.print(board[i][j].color);
    		}
    		System.out.println();
    	}
    }
    
    public void showSize()
    {
    	for(int i = 0; i < board.length; i++)
    	{
    		for(int j = 0; j < board[0].length; j++)
    		{
    			System.out.print(board[i][j].squareSize);
    		}
    		System.out.println();
    	}
    }
    

		public void markBoard(int size)
		{
			int ht = board.length;
			int wid = board[0].length;
			boolean flag = false;
			for(int i = 0; i+size <= ht; i++)
			{
				for(int j = 0; j+size <= wid; j++)
				{
					flag = false;
					Cell currCell = board[i][j];
					for(int r = 0; r < size; r++)
					{
						int currColor = (currCell.color+r)%2;
						for(int c = 0; c < size; c++)
						{
							if(board[i+r][j+c].color == currColor && board[i+r][j+c].used == false)
								currColor = (currColor + 1)%2;
							else
							{
								flag = true;
								break;
							}
						}
						if(flag)
							break;
					}
					if(flag)
						continue;
					else
					{
						currCell.squareSize = size;
						for(int r = 0; r < size; r++)
						{
							for(int c = 0; c < size; c++)
							{
								board[i+r][j+c].used = true;
							}
						}
					}	
				}
			}
		}

    
    // Needs to println number of sizes then the actual stuff
    public void readBoard()
    {
    	int[] numBoxes = new int[Math.max(board.length, board[0].length)+1];
    	for(int i = 0; i < board.length; i++)
    	{
    		for(int j = 0; j < board[0].length; j++)
    		{
    			int size = board[i][j].squareSize;
    			if(size != 0)
    				numBoxes[size] = numBoxes[size]+1;
    		}
    	}
    	int counter = 0;
    	for(int i = 0; i < numBoxes.length; i++)
    	{
    		if(numBoxes[i] > 0)
    			counter++;
    	}
    	System.out.println(counter);
    	for(int i = numBoxes.length-1; i > 0; i--)
    	{
    		if(numBoxes[i] > 0)
    		{
    			System.out.println(i + " " + numBoxes[i]);
    		}
    	}
    }
    
    public static void main(String[] args)
    {
    	String filename = args[0];
    	try{
    	File file = new File(filename);
    	
    	Scanner sc = new Scanner(file);
    	
    	int numCases = sc.nextInt();
    	for(int i = 0; i < numCases; i++)
    	{
    		int height = sc.nextInt();
    		int width = sc.nextInt();
    		Cell[][] currBoard = new Cell[height][width];
    		for(int h = 0; h < height; h++)
    		{
    			String nextLine = sc.next();
    			int w = 0;
    			for(int x = 0; x < nextLine.length(); x++)
    			{
    				w = x*4;
    				char hexChar = nextLine.charAt(x);
    				Cell a = new Cell(0);
    				Cell b = new Cell(1);
    				if(hexChar == '0')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == '1')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    				else if(hexChar == '2')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == '3')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    				else if(hexChar == '4')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == '5')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    				else if(hexChar == '6')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == '7')
    				{
    					currBoard[h][w] = a.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    				else if(hexChar == '8')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == '9')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    				else if(hexChar == 'A')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == 'B')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = a.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    				else if(hexChar == 'C')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == 'D')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = a.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    				else if(hexChar == 'E')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = a.deepCopy();
    				}
    				else if(hexChar == 'F')
    				{
    					currBoard[h][w] = b.deepCopy();
    					currBoard[h][w+1] = b.deepCopy();
    					currBoard[h][w+2] = b.deepCopy();
    					currBoard[h][w+3] = b.deepCopy();
    				}
    			}
    			
    			
    			
    		}
    		Chessboards myBoard = new Chessboards(currBoard);
    		for(int s = Math.min(height, width); s > 0; s--)
    		{myBoard.markBoard(s);}
    			System.out.print("Case #" + (i+1) + ": ");
    			myBoard.readBoard();
    	}
    	}
    	catch(FileNotFoundException e){
    		System.out.println(e);
    	}
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        public void markBoard()
    {
    	int ht = board.length;
    	int wid = board[0].length;
    	boolean flag = false;
    	for(int i = 0; i < ht; i++)
    	{
    		for(int j = 0; j < wid; j++)
    		{
    			Cell currCell = board[i][j];
    			if(currCell.used)
    			{
    				continue;
    			}
    			else
    			{
    				currCell.used = true;
    				int size = 1;
    				while(i+size < ht && j + size < wid)
    				{
    					flag = false;
    					int startColor = (currCell.color+size)%2;
    					for(int right = 0; right < size + 1; right++)
    					{
    						if(board[i+right][j+size].color == startColor && board[i+right][j+size].used == false)
    							startColor = (startColor+1)%2;
    						else
    						{
    							flag = true;
    							break;
    						}
    					}
    					startColor = (currCell.color+size)%2;
    					for(int bottom = 0; bottom < size + 1; bottom++)
    					{
    						if(board[i+size][j+bottom].color == startColor && board[i+size][j+bottom].used == false)
    							startColor = (startColor+1)%2;
    						else
    						{
    							flag = true;
    							break;
    						}
    					}
    					if(flag)
    						break;
    					else{
    						size += 1;
    					}
    				}
    				currCell.squareSize = size;
    				for(int r = 0; r < size; r++)
    				{
    					for(int c = 0; c < size; c++)
    					{
    						board[i+r][j+c].used = true;
    					}
    				}
    			}
    		}
    	}
    }
}