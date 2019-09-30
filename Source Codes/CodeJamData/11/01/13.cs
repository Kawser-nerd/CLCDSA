using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2011
{
    class Program
    {
        class SolveTestCase
        {
            enum Robot
            {
                Orange,
                Blue
            }

            int mNumberOfMoves = 0;
            List<Robot> mNextMove = new List<Robot>();
            List<int> mOrangeMoves = new List<int>();
            List<int> mBlueMoves = new List<int>();
            int mOrangePosition = 1;
            int mBluePosition = 1;

            public SolveTestCase( int caseNumber )
            {

                string testCaseInput = Console.ReadLine();
                string[] splitInput = testCaseInput.Split( " ".ToCharArray() );
                for ( int i = 1; i < splitInput.Length; i += 2 )    // Don't bother with the number input
                {
                    if ( splitInput[i] == "O" )
                    {
                        mOrangeMoves.Add( int.Parse( splitInput[i + 1] ) );
                        mNextMove.Add( Robot.Orange );
                    }
                    else
                    {
                        mBlueMoves.Add( int.Parse( splitInput[i + 1] ) );
                        mNextMove.Add( Robot.Blue );
                    }
                }

                while ( mNextMove.Count > 0 )
                {
                    if ( mNextMove[0] == Robot.Orange )
                    {
                        mNumberOfMoves += MoveRobot( ref mOrangeMoves, ref mOrangePosition, ref mBlueMoves, ref mBluePosition, mNextMove[0] );
                    }
                    else
                    {
                        mNumberOfMoves += MoveRobot( ref mBlueMoves, ref mBluePosition, ref mOrangeMoves, ref mOrangePosition, mNextMove[0] );
                    }
                    mNextMove.RemoveAt( 0 );
                }

                Console.WriteLine( String.Format( "Case #{0}: {1}", caseNumber, mNumberOfMoves ) );
            }

            private int MoveRobot( ref List<int> robotMoves, ref int robotPosition, ref List<int> otherRobotMoves, ref int otherRobotPosition, Robot robot)
            {
                int desiredIndex = robotMoves[0];
                int minMoveCount = Math.Abs( desiredIndex - robotPosition ) + 1;    // Add 1 to push the button!

                robotPosition = desiredIndex;
                robotMoves.RemoveAt( 0 );

                //Console.Write( "{0} - Robot {1} {2} {3}", mNumberOfMoves + minMoveCount, robot.ToString(), (minMoveCount == 1) ? "pressed" : "moved to and pressed", robotPosition );

                // Move the other robot if applicable
                if ( otherRobotMoves.Count > 0 )
                {
                    int otherRobotDesiredMovement = otherRobotMoves[0] - otherRobotPosition;
                    int otherRobotActualMovement = Math.Sign( otherRobotDesiredMovement ) *
                                                   Math.Min( Math.Abs( otherRobotDesiredMovement ), minMoveCount );
                    otherRobotPosition += otherRobotActualMovement;

                    //Console.Write( " and other robot {1} {2}", robot.ToString(), ( otherRobotActualMovement == 0 ) ? "stayed at" : String.Format( "moved to {0} toward", otherRobotPosition ), otherRobotMoves[0] );
                }

                //Console.WriteLine();

                return minMoveCount;
            }
        }

        static void Main( string[] args )
        {
            int testCases = int.Parse( Console.ReadLine() );
            for ( int i = 0; i < testCases; ++i )
            {
                new SolveTestCase( i + 1 );
            }

            Console.ReadLine();
        }
    }
}
