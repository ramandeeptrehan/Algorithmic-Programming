/*

References:

Algorithm: Tushar Roy's lesson
Code: From Tushar Roy's repository

Problem Statement: 
The N Queen Problem is the problem of placing N chess queens on a N×N chessboard so that no two queens attack each other

Date: 25 September, 2017

*/

import java.util.Scanner;

public class NQueenProblemBacktracking {
	
	class Position
	{
		int row;
		int column;
		
		Position(int row, int column)
		{
			this.row = row;
			this.column = column;
		}
	}
	
	public Position[] solveNQueen(int n)
	{
		Position[] position = new Position[n];
		
		boolean hasSolution = solveNQueenUtil(position, n, 0); // 0 is first row. Going row by row
		
		if(hasSolution == true)
			return position;
		else
			return new Position[0];
	
	}
	
	public boolean solveNQueenUtil(Position[] position, int n, int row)
	{
		if(row == n)
		{
			return true;
		}
		// try for all columns for given row
		for(int column = 0; column<n; column++)
		{
			// Assuming it's safe to put Q at Position(row, column). Will check now
			boolean isSafe = true;
			
			// test to check attack from previously placed queens
			for(int queen = 0; queen<row; queen++)
			{
				// attack condition
				if(position[queen].column == column || position[queen].row + position[queen].column == row + column
						|| position[queen].row - position[queen].column == row-column)
				{
					isSafe = false;
					break;
				}
			}
			
			if(isSafe == true)
			{
				position[row] = new Position(row, column);
				if(solveNQueenUtil(position, n, row+1) == true)
					{
						return true;
					}
			}
		} // end of main for loop
		
		// if not able to place queen in any column for particular row, return false
		return false;
	}
	
	void printSolution(Position[] position)
	{
		for(int i=0; i<position.length; i++)
		{
			System.out.println("Row " + i + " : "+ position[i].row + " , " + position[i].column);
		}
			
	}
	public static void main(String[] args)
	{
		NQueenProblemBacktracking obj = new NQueenProblemBacktracking();
		
		// Taking input from user
		System.out.println("Enter value of n for nxn board:");
		int n;
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		
		Position[] position = obj.solveNQueen(n);
		
		// Printing the positions for queens in each row
		// NOTE: If question asks print the matrix (boolean), we can do that using position array
		obj.printSolution(position);
	}

}
